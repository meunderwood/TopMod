/*
*
* ***** BEGIN GPL LICENSE BLOCK *****
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software  Foundation,
* Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*
* The Original Code is Copyright (C) 2005 by xxxxxxxxxxxxxx
* All rights reserved.
*
* The Original Code is: all of this file.
*
* Contributor(s): none yet.
*
* ***** END GPL LICENSE BLOCK *****
*
* Short description of this file
*
* name of .hh file containing function prototypes
*
*/

#include "DLFLDual.hh"
#include "DLFLSubdiv.hh"
#include <DLFLCore.hh>

namespace DLFL {

  void createDual(DLFLObjectPtr obj, bool accurate) {
    // Using "correct" methods seems to be VERY slow
    // We will use it only if we want accurate dual
    // Otherwise we will use old method
    if ( accurate ) {
      // Dual operation using face subdivision into quads,
      // followed by deleting old edges and cleanup of winged vertices

      // Keep count of old number of vertices
      // All old edges have to be deleted. But since old edges will be subdivided
      // we have to access the edges through the old vertices
      int num_old_verts = obj->num_vertices();

      DLFLVertexPtrList::iterator vpfirst, vplast;
      DLFLVertexPtr vp;
       

      // Do quad subdivision of all faces
      subdivideAllFaces(obj,true);

      /*
      cout << "Vertex 16 is of degree " << 
        obj->getVertexPtrID(16)->valence() << endl;
      DLFLFaceVertexPtrList fvpList = obj->getVertexPtrID(16)->getFaceVertexList();
      for (DLFLFaceVertexPtrList::iterator it = fvpList.begin();
          it != fvpList.end(); ++it){
        cout << (*it)->next()->getVertexPtr()->getID() << ",";
      }
      cout << endl;
      for (DLFLFaceVertexPtrList::iterator it = fvpList.begin();
          it != fvpList.end(); ++it){
        (*it)->getFacePtr()->boundaryWalk();
      }
      return;
      */

      // Go through all the old vertices and delete all edges connected to them
      int vcount = 0;
      DLFLEdgePtrArray eparray;
      vpfirst = obj->beginVertex(); vplast = obj->endVertex();
      // deleteEdge may remove vertices.
      DLFLEdgePtrArray to_be_removed;
      while( vcount < num_old_verts ) {
        vp = (*vpfirst); ++vpfirst; ++vcount;
        vp->getEdges(eparray);
        for (int i=0; i < eparray.size(); ++i)
          to_be_removed.push_back(eparray[i]);
          //deleteEdge(obj,eparray[i],true);
      }

      for (DLFLEdgePtrArray::iterator it = to_be_removed.begin();
          it != to_be_removed.end(); ++it) {
          deleteEdge(obj, *it, true);


          /*
          DLFLVertexPtr vp1 = obj->getVertexPtrID(16);
          if (vp1->getID() == 16 && vp1->valence() == 2) { 
            cout << "16 becomes valence 2!!!" << endl;
            break;
          }
          */
      }

      // Cleanup valence-2 vertices
      cleanupWingedVertices(obj);
    } else {
      // Go through list of faces and create centroids
      // Also make sure face ids are consecutive

      DLFLFacePtrList::iterator fl_first, fl_last;
      DLFLFacePtr fp;

      Vector3d cen;
      StringStream rw,mw;
			obj->writeMTL(mw);

      // Traverse all faces, find centroid and output to stream
      // Also call makeUnique to ensure face ids are consecutive
      fl_first = obj->beginFace(); fl_last = obj->endFace();
      while( fl_first != fl_last ) {
				fp = (*fl_first); ++fl_first;
				fp->makeUnique();
				cen = fp->geomCentroid();	   
				rw << "v " << cen[0] << " " << cen[1] << " " << cen[2] << endl;
      }

      // Get ID of first face to determine offset for index into vertex list
      int fistart = (obj->firstFace())->getID();

      // Now traverse for all vertices, get all faces attached to it
      // and create dual faces accordingly and output to filestream
      DLFLVertexPtrList::iterator vl_first, vl_last;
      DLFLVertexPtr vp;
      DLFLFaceVertexPtrArray fvparray;

      vl_first = obj->beginVertex(); vl_last = obj->endVertex();
      while ( vl_first != vl_last ) {
        vp = (*vl_first); ++vl_first;
        // Get the face vertices pointing to this vertex in an array
        vp->getFaceVertices(fvparray);
        if ( fvparray.size() > 0 ) {
          // Start from one face vertex (first) and traverse
          // the face vertices pointing to this vertex according to the
          // rotation order. This wont always be the same as the order
          // in the list of face vertices in the vertex.
          DLFLFaceVertexPtr startfvp = fvparray[0];
          DLFLFaceVertexPtr curfvp = startfvp;

          int index=0;
          fvparray[index++] = curfvp;

          // Use vnext and not next, since we want rotation around vertex
          // Use the same array to store the face vertices in the correct
          // rotation order, since the size will be the same
          curfvp = curfvp->vnext();
          while ( curfvp != startfvp) {
            fvparray[index++] = curfvp;
            curfvp = curfvp->vnext();
          }

          // Create the dual face corresponding to this vertex by
          // going through the array created above, finding the corresponding face
          // and using the ID to index into the list of vertices output earlier.
          // Note that traversal here is in reverse because rotation order around
          // vertex is opposite to that of the faces
          rw << "f"; 
          while( index > 0 ) {
            rw << " ";
            rw << fvparray[--index]->getFaceID()-fistart+1;
          }
        }
        fvparray.clear();
        rw << endl;
      }
      rw << endl << endl;
      rw << flush;
      obj->readObject(rw,mw);
    }
  }
}
