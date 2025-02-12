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
*/

/**
 * \file DLFLFace.hh
 */

#ifndef _DLFL_FACE_HH_
#define _DLFL_FACE_HH_

// Class for a Face to be used in the DLFLObject class
// Based on the OBJFace class

// A DLFLFace is just a list of DLFLFaceVertexes
// The ordering of the DLFLFaceVertexes is important
// A DLFLFace can be implemented as a 2-3 Tree or as a linked list

#include "DLFLCommon.hh"
#include "DLFLFaceVertex.hh"
#include "DLFLMaterial.hh"
#include "FreeList.hh"
//#include <Light/Light.hh>

namespace DLFL {

  class DLFLFace {
  private:
    static NextOnFreeList *face_pool;

  public :
    static void setLastID( uint id ) {
      if( id > suLastID )
				suLastID = id;
    };
    // Override new operator
    inline void* operator new(size_t size) {
      if(face_pool == NULL) {
        expandFacePool();
      }
      NextOnFreeList *head = face_pool;
      face_pool = face_pool->next;
      return head;
    };
    // Override delete operator
    inline void operator delete(void* to_be_deleted) {
      NextOnFreeList *head = static_cast<NextOnFreeList *>(to_be_deleted);
      head->next = face_pool;
      face_pool = head;
    };
    inline void operator delete(void* to_be_deleted, size_t size) {
      NextOnFreeList *head = static_cast<NextOnFreeList *>(to_be_deleted);
      head->next = face_pool;
      face_pool = head;
    };

    static void deleteFacePool() {
      NextOnFreeList *head;
      while(face_pool != NULL) {
        head = face_pool;
        face_pool = face_pool->next;
        delete[] head;
      }
    };

  private:
    enum {EXPANSION_SIZE = 1024};
    static void expandFacePool() {
      //Allocate an object large enough to hold both objects
      size_t size = (sizeof(DLFLFace) > sizeof(NextOnFreeList)) ? sizeof(DLFLFace) :
                    sizeof(NextOnFreeList);
      NextOnFreeList *runner = (NextOnFreeList *)malloc(size);
      face_pool = runner;
      for(int i = 0; i < EXPANSION_SIZE; i++) {
        runner->next = (NextOnFreeList *)malloc(size);
        runner = runner->next;
      }
      runner->next = NULL;
    };
  protected :

    static uint suLastID;                             //!< Distinct ID for each instance

    static uint newID(void) {                           //!< Generate a new unique ID
      uint temp = suLastID;
      suLastID++;
      return temp;
    }
     
    uint uID;                                         //!< ID for this Face
    DLFLFaceVertexPtr     head;                       //!< Head of list of face-vertex pointers
    DLFLMaterialPtr       matl_ptr;                   //!< Pointer to material for this face
    DLFLFaceType          ftType;                     //!< For use in subdivision surfaces
    Vector3d              auxcoords;                  //!< Coords for use during subdivs, etc.
    Vector3d              auxnormal;                  //!< Extra storage for normal

  public :
     
    Vector3d              centroid;                   //!< Centroid of this face (not always current)
    Vector3d              normal;                     //!< Normal to this face. Not always correct/current
    unsigned long         flags;                      //!< Variable for general use to store flags, etc.
    uint ismarked;

  protected :

     // Assign a unique ID for this instance
    void assignID(void) {
      uID = DLFLFace :: newID();
      ismarked = 0;
    }

    // Advance the pointer by given number of nodes. Similar to STL advance algorithm
    DLFLFaceVertexPtr advance(DLFLFaceVertexPtr ptr, uint num) const;

    // Copy all face-vertices from another face specified by it's head pointer
    void copy(DLFLFaceVertexPtr ptr);

  public :

    // Default and 1 arg constructor
    DLFLFace( DLFLMaterialPtr tmp = NULL);

    // Copy constructor
    DLFLFace(const DLFLFace& face);

    // Destructor
    ~DLFLFace();

    // Assignment operator
    DLFLFace& operator = (const DLFLFace& face);

    DLFLFacePtr copy(void) const {
      DLFLFacePtr new_face = new DLFLFace(*this);
      return new_face;
    }

    // Dump contents of object
    void dump(ostream& o) const;
        
    Vector3d geomSum(void) const;

    // Sum of texture coordinates
    Vector2d textureSum(void) const;

    // Color sum
    RGBColor colorSum(void) const;

    // Normal sum
    Vector3d normalSum(void) const;

    // Get all sums
    void getSums(Vector3d& sumg, Vector2d& sumtc, RGBColor& sumc, Vector3d& sumn) const;

    // Update the centroid of this face
    void updateCentroid(void);
     
    // Update the centroid of this face and return it
    Vector3d geomCentroid(void) {
      updateCentroid();
      return centroid;
    }

    // Compute the texture centroid
    Vector2d textureCentroid(void) const;

    // Compute the color centroid
    RGBColor colorCentroid(void) const;

    // Update the normal of this face
    void updateNormal(void);
     
    // Compute the normal centroid
    Vector3d normalCentroid(void) {
      //updateNormal();
      return normal;
    }

    // Compute the normal for this face and send it to the face-vertices
    Vector3d computeNormal(void);

    // Compute the normal for each face-vertex and store it in the face-vertex itself
    // Don't do any averaging, etc.
    void storeNormals(void);
     
    // Compute all centroids
    void getCentroids(Vector3d& cen, Vector2d& texc, RGBColor& colc, Vector3d& nc) const;

    //--- Query Functions ---//

    uint getID(void) const {
      return uID;
    }

    DLFLFaceType getType(void) const {
      return ftType;
    }

    DLFLMaterialPtr material(void) const {
      return matl_ptr;
    }

    Vector3d getAuxCoords(void) const {
      return auxcoords;
    }

    Vector3d getAuxNormal(void) const {
      return auxnormal;
    }
     
    Vector3d getNormal(bool update=false) {
			if(update)
				updateNormal();
      return normal;
    }

    Vector3d getCentroid(void) const {
      return centroid;
    }

    //--- Mutative Functions ---//

    void makeUnique(void) {
      assignID();
    }

    // Delete all the face-vertices of this face
    void destroy(void);
     
    void reset(void) {
      destroy();
      matl_ptr = NULL;
    }

    DLFLFaceVertexPtr addVertex(const DLFLFaceVertex& dfv);        // Insert a copy
    DLFLFaceVertexPtr addVertex(DLFLFaceVertexPtr dfvp);           // Insert a copy
    void addVertexPtr(DLFLFaceVertexPtr dfvp);        // Insert the pointer

    // Delete given FaceVertex from face. Adjust pointers of adjacent face-vertices
    // Memory for given face-vertex is not freed. Given FaceVertex must belong to this Face
    // If given face-vertex is the only face-vertex in this face, nothing is done (for now)
    void deleteVertexPtr(DLFLFaceVertexPtr dfvp);

    // Same as above, but more correct function name
    void deleteFaceVertexPtr(DLFLFaceVertexPtr dfvp) {
      deleteVertexPtr(dfvp);
    }
     
    // Get the coordinates of the vertices of the face
    void getVertexCoords(Vector3dArray& verts);

    // STL list type access to the Face
    DLFLFaceVertexPtr front(void) {
      return head;
    }

    DLFLFaceVertexPtr back(void) {
      DLFLFaceVertexPtr b = NULL;
      if ( head ) b = head->prev();
      return b;
    }

    // Return the first/last element of the list
    DLFLFaceVertexPtr firstVertex(void) {
      return front();
    }

    DLFLFaceVertexPtr lastVertex(void) {
      return back();
    }

    // Set the material pointer
    void setMaterial(DLFLMaterialPtr mptr);

    void setType(DLFLFaceType type) {
      ftType = type;
    }

    void resetType(void) {
      ftType = FTNormal;
    }

    void setAuxCoords(const Vector3d& p) {
      auxcoords = p;
    }

    void setAuxNormal(const Vector3d& n) {
      auxnormal = n;
    }
     
    void addToAuxCoords(const Vector3d& p) {
      auxcoords += p;
    }

    void addToAuxNormal(const Vector3d& n) {
      auxnormal += n;
    }
     
    void resetAuxCoords(void) {
      auxcoords.reset();
    }

    void resetAuxNormal(void) {
      auxnormal.reset();
    }
     
    uint size(void) const;                             // No. of vertices in this face
    uint numFaceVertexes(void) const {
      return size();
    }

    void resetTypeDeep(void); // Reset type of Face and all FaceVertexes in this Face

    // Compute color for each corner using given light and using material of Face
    //void computeLighting(LightPtr lightptr);

    // Update the DLFLFacePtr for each DLFLFaceVertex
    void updateFacePointers(void);
    void resetFacePointers(void);
     
    // Update the DLFLFaceVertexList for each DLFLVertex referred to by each DLFLFaceVertex
    void addFaceVerticesToVertices(void);
    void deleteFaceVerticesFromVertices(void);

    // Update the DLFLFaceVertexPtr for each DLFLEdge connected to each DLFLFaceVertex
    void addFaceVerticesToEdges(void);
    void deleteFaceVerticesFromEdges(void);

    // Update DLFLEdges and DLFLVertices - above functions combined for efficiency
    void addFaceVerticesToVerticesAndEdges(void);
    void deleteFaceVerticesFromVerticesAndEdges(void);
     
    // Create an array of DLFLEdges for this DLFLFace. Number of DLFLEdges in the array
    // is returned. Memory will be allocated inside this function, which should
    // be freed by the caller. Pass a pointer to the array (DLFLEdge **)
    int getEdges(DLFLEdge ** edges);

    // Get the edges in the face. Different from previous function. Doesn't create
    // new edges, simply stores existing edge pointer from the face vertices into
    // the STL array or STL linked list
    void getEdges(DLFLEdgePtrArray& edges);
    void getEdges(DLFLEdgePtrList& edges);

    // Get the corners in the face. Stores the existing DLFLFaceVertexPtr's in the face
    // into the array
    void getCorners(DLFLFaceVertexPtrArray& corners);

		// Helpful for python interface
		DLFLFaceVertexPtr findFaceVertex( uint vertexId ) const;
		DLFLFaceVertexPtr findFaceVertexByID( uint faceVertexId ) const;

    // Get the corners and the coordinates
    void getCornersAndCoords(DLFLFaceVertexPtrArray& corners, Vector3dArray& coords);

    // Does this Face contain the given face-vertex?
    bool contains(DLFLFaceVertexPtr dfvp);

    // Does this face share only one vertex with the given face?
    bool sharesOneVertex(DLFLFacePtr dfp);

    void getNeighboringFaces(DLFLFacePtrArray& fparray);

    // Find the DLFLFaceVertex following the given DLFLFaceVertex in this DLFLFace
    // If only one DLFLFaceVertex is there in the DLFLFace returns itself
    DLFLFaceVertexPtr nextFaceVertex(DLFLFaceVertexPtr fvptr);

    // Find the DLFLFaceVertex preceding the given DLFLFaceVertex in this DLFLFace
    // If only one DLFLFaceVertex is there in the DLFLFace returns itself
    DLFLFaceVertexPtr prevFaceVertex(DLFLFaceVertexPtr fvptr);

    // Find the FaceVertex which is closest to the given point
    DLFLFaceVertexPtr findClosest(const Vector3d& p);

    // Find the two corners which are closest to each other in the two faces
    // The passed DLFLFaceVertex pointers will be set to the closest corners,
    // the first one from the first face and the second one from the second face
    static void findClosestCorners(DLFLFacePtr fp1, DLFLFacePtr fp2,
				   DLFLFaceVertexPtr& fvp1, DLFLFaceVertexPtr& fvp2);

    // Add a new DLFLFaceVertex after/before a given DLFLFaceVertex in this DLFLFace
    DLFLFaceVertexPtr insertAfter(DLFLFaceVertexPtr fvptr, DLFLFaceVertexPtr new_fvp, bool copy=true);
    DLFLFaceVertexPtr insertBefore(DLFLFaceVertexPtr fvptr, DLFLFaceVertexPtr new_fvp, bool copy=true);

    // Reorder the face-vertices so that the given face-vertex is the first one
    // Given face vertex should belong to this face
    void reorder(DLFLFaceVertexPtr fvptr);

  public :
    // Reverse the face - reverses the order of the face-vertices
    // WARNING!! This operation invalidates the DLFL structure. All edges
    // associated with this face will be in an invalid state.
    void reverse(void);

  protected :
    // Classes which need to access the reverse method should be declared as friends here
    friend class DLFLObject;

  public :
     
    // Output the boundary walk of the face
    vector<int> vertexWalk( ) const;
    vector<int> edgeWalk( ) const;
    void boundaryWalk(void) const;
    void print(void) const {
      boundaryWalk();
    }
  
    friend void boundaryWalk(DLFLFacePtr faceptr);
/*
    friend void boundaryWalk(DLFLFacePtr faceptr) {
      faceptr->boundaryWalk();
    }
*/
    friend void boundaryWalk(const DLFLFace& face);
/*
    friend void boundaryWalk(const DLFLFace& face) {
      face.boundaryWalk();
    }
*/
     
    // For debugging
    void printPointers(void) const;
     
    // Write out the Face in OBJ format to an output stream - source for more info
    // min_id is the minimum ID value. It will subtracted from the ID before output
    void objWrite(ostream& o, uint min_id) const;
    void objWriteWithNormals(ostream& o, uint min_id, uint& normal_id_start) const;
    void objWriteWithTexCoords(ostream& o, uint min_id,
			       uint& tex_id_start) const;
    void objWriteWithNormalsAndTexCoords(ostream& o, uint min_id,
					 uint& normal_id_start,
					 uint& tex_id_start) const;

    // Write out the normals for each vertex in the Face in OBJ format
    void objWriteNormals(ostream& o) const;

    // Write out the texture coordinates for each vertex in the Face in OBJ format
    void objWriteTexCoords(ostream& o) const;

    // Write out the face in DLFL format
    void writeDLFL(ostream& o) const;

    // Write out the face in DLFL format but in reverse order. Useful for crust modeling
    void writeDLFLReverse(ostream& o) const;
     
    // Access the face-vertex specified by index. No range checks done
    DLFLFaceVertexPtr facevertexptr(uint index);
    DLFLFaceVertex& facevertex(uint index);
    DLFLFaceVertex facevertex(uint index) const;

    // Access the vertex specified by index. No range checks done
    DLFLVertexPtr vertexptr(uint index);
    DLFLVertex& vertex(uint index);
    DLFLVertex vertex(uint index) const;

    // Access the coordinates of the vertex specified by index. No range checks done
    Vector3d& vertex_coords(uint index);
    Vector3d vertex_coords(uint index) const;

    // Access color and normal of face vertex specified by index
    RGBColor& fv_color(uint index);
    RGBColor fv_color(uint index) const;
     
    Vector3d& fv_normal(uint index);
    Vector3d fv_normal(uint index) const;

    // Set the color of all face vertices of this face
    void setColor(const RGBColor& col);
    void setColor(double r, double g, double b);

    // FOR QUADS ONLY - Randomly assign texture coordinates to the 4 corners to match a 1,1 square
    void randomAssignTexCoords(void);
     
    void updateMaterial(void);

		float getArea();

    //--- Rendering subroutines ---//

    // Call glBegin with the appropriate macro depending on no of vertices
    // This is for filled polygons.
    /*     static void glBeginP(int num)
	   {
	   switch ( num )
	   {
	   case 0 :
	   return;
	   case 1 :
	   glBegin(GL_POINTS); break;
	   case 2 :
	   glBegin(GL_LINES); break;
	   case 3 :
	   glBegin(GL_TRIANGLES); break;
	   case 4 :
	   glBegin(GL_QUADS); break;
	   default :
	   glBegin(GL_POLYGON);
	   }
	   }

	   // Call glBegin with the appropriate macro depending on no of vertices
	   // This is for outlined polygons.
	   static void glBeginO(int num)
	   {
	   switch ( num )
	   {
	   case 0 :
	   return;
	   case 1 :
	   glBegin(GL_POINTS); break;
	   case 2 :
	   glBegin(GL_LINES); break;
	   default :
	   glBegin(GL_LINE_LOOP);
	   }
	   }*/

    void for_each(void (*func)(DLFLFaceVertexPtr)) const;
    /*
      void render_FVN(void) const                       // Render using FV normals
      {
      DLFLFace :: glBeginP(size());
      for_each(glVertexNp);
      glEnd();
      }

      void render_FVC(void) const                       // Render using FV colors
      {
      DLFLFace :: glBeginP(size());
      for_each(glVertexCp);
      glEnd();
      }

      void render_FVCN(void) const                      // Render using FV colors and normals
      {
      DLFLFace :: glBeginP(size());
      for_each(glVertexCNp);
      glEnd();
      }

      void render_FV(void) const                        // Render without using FV colors or normals
      {
      DLFLFace :: glBeginP(size());
      for_each(glVertexOFVp);
      glEnd();
      }

      //--- Same as above but with texturing also ---//
     
      void render_FVNT(void) const
      {
      DLFLFace :: glBeginP(size());
      for_each(glVertexNTp);
      glEnd();
      }

      void render_FVCT(void) const
      {
      DLFLFace :: glBeginP(size());
      for_each(glVertexCTp);
      glEnd();
      }

      void render_FVCNT(void) const
      {
      DLFLFace :: glBeginP(size());
      for_each(glVertexCNTp);
      glEnd();
      }

      void render_FVT(void) const
      {
      DLFLFace :: glBeginP(size());
      for_each(glVertexOFVTp);
      glEnd();
      }

      void render(void) const                           // Default render - render_FVN
      {
      render_FVN();
      }

      //-- Friend versions of above functions --//
     
      void outline_FVC(void) const                      // Render outline using FV colors
      {
      DLFLFace :: glBeginO(size());
      for_each(glVertexCp);
      glEnd();
      }

      void outline_FV(void) const                       // Render outline
      {
      DLFLFace :: glBeginO(size());
      for_each(glVertexOFVp);
      glEnd();
      }

      void outline(void) const                          // Default outline - outline_FV
      {
      outline_FV();
      }

      //--- These friend versions of above functions allow use of STL algorithms ---//

      friend void render_FVN(const DLFLFace& face)
      {
      face.render_FVN();
      }

      friend void render_FVC(const DLFLFace& face)
      {
      face.render_FVC();
      }

      friend void render_FVCN(const DLFLFace& face)
      {
      face.render_FVCN();
      }

      friend void render_FV(const DLFLFace& face)
      {
      face.render_FV();
      }

      friend void render_FVNT(const DLFLFace& face)
      {
      face.render_FVNT();
      }

      friend void render_FVCT(const DLFLFace& face)
      {
      face.render_FVCT();
      }

      friend void render_FVCNT(const DLFLFace& face)
      {
      face.render_FVCNT();
      }

      friend void render_FVT(const DLFLFace& face)
      {
      face.render_FVT();
      }

      friend void render(const DLFLFace& face)
      {
      face.render();
      }

      friend void outline_FVC(const DLFLFace& face)
      {
      face.outline_FVC();
      }

      friend void outline_FV(const DLFLFace& face)
      {
      face.outline_FV();
      }

      friend void outline(const DLFLFace& face)
      {
      face.outline();
      }


      //--- The DLFLFacePtr versions are for use by the DLFLMaterial class ---//

      // The function names have been changed to prevent STL instantiation errors
      // because of conflicts with other functions with similar names (DLFLMaterial)

      friend void facerender_FVN(const DLFLFacePtr& face)
      {
      face->render_FVN();
      }

      friend void facerender_FVC(const DLFLFacePtr& face)
      {
      face->render_FVC();
      }

      friend void facerender_FVCN(const DLFLFacePtr& face)
      {
      face->render_FVCN();
      }

      friend void facerender_FV(const DLFLFacePtr& face)
      {
      face->render_FV();
      }

      friend void facerender_FVNT(const DLFLFacePtr& face)
      {
      face->render_FVNT();
      }

      friend void facerender_FVCT(const DLFLFacePtr& face)
      {
      face->render_FVCT();
      }

      friend void facerender_FVCNT(const DLFLFacePtr& face)
      {
      face->render_FVCNT();
      }

      friend void facerender_FVT(const DLFLFacePtr& face)
      {
      face->render_FVT();
      }

      friend void facerender(const DLFLFacePtr& face)
      {
      face->render();
      }

      friend void faceoutline_FVC(const DLFLFacePtr& face)
      {
      face->outline_FVC();
      }

      friend void faceoutline_FV(const DLFLFacePtr& face)
      {
      face->outline_FV();
      }

      friend void faceoutline(const DLFLFacePtr& face)
      {
      face->outline();
      }*/

    friend ostream& operator << (ostream& o, const DLFLFace& face);
  };

  void boundaryWalk(DLFLFacePtr faceptr);
  void boundaryWalk(const DLFLFace& face);


} // end namespace

#endif /* #ifndef _DLFL_FACE_HH_ */

