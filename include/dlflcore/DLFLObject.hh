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
 * \file DLFLObject.hh
 */

#ifndef _DLFL_OBJECT_HH_
#define _DLFL_OBJECT_HH_

#include <map>
/**
* TRANSLATOR DLFL::DLFLObject
*   
* Necessary for lupdate.
*/

/**
* \brief DLFLObject class - The Doubly Linked Face List object classs
* 
* The Doubly Linked Face List object classs
* Contains a vertex list, edge list and a face list
* The lists actually store pointerss
* 
*/

#include "DLFLCommon.hh"
#include "DLFLVertex.hh"
#include "DLFLFaceVertex.hh"
#include "DLFLEdge.hh"
#include "DLFLFace.hh"
#include "DLFLMaterial.hh"
#include <Graphics/Transform.hh>



namespace DLFL {

class DLFLObject {
public :

  /// Constructor
  DLFLObject()
    : position(), scale_factor(1), rotation(),
      vertex_list(), edge_list(), face_list(), /* patch_list(), patchsize(4)*/ 
      vertex_idx(), edge_idx(), face_idx() {
    assignID();
    // Add a default material
    matl_list.push_back(new DLFLMaterial("default",0.5,0.5,0.5));
    mFilename = NULL;
    mDirname = NULL;
    TileMapBase[std::string("0000")]=std::string("0000");
    TileMapBase[std::string("0100")]=std::string("0001");
    TileMapBase[std::string("1000")]=std::string("0101");
    TileMapBase[std::string("1100")]=std::string("0100");
    TileMapBase[std::string("0001")]=std::string("1000");
    TileMapBase[std::string("0101")]=std::string("1001");
    TileMapBase[std::string("1001")]=std::string("1101");
    TileMapBase[std::string("1101")]=std::string("1100");
    TileMapBase[std::string("0010")]=std::string("1010");
    TileMapBase[std::string("0110")]=std::string("1011");
    TileMapBase[std::string("1010")]=std::string("1111");
    TileMapBase[std::string("1110")]=std::string("1110");
    TileMapBase[std::string("0011")]=std::string("0010");
    TileMapBase[std::string("0111")]=std::string("0011");
    TileMapBase[std::string("1011")]=std::string("0111");
    TileMapBase[std::string("1111")]=std::string("0110");
  };

  /// Destructor
  ~DLFLObject( ) {
    clearLists();
    if( mFilename ) { delete [] mFilename; mFilename = NULL; }
    if( mDirname ) { delete [] mDirname; mDirname = NULL; }
  };

protected :

  // Distinct ID for each instance
  static uint suLastID;

  // Generate a new unique ID
  static uint newID( ) {
    uint temp = suLastID;
    suLastID++;
    return temp;
  };

public :
 
  static Transformation tr;                         // For doing GL transformations

  DLFLVertexPtrArray sel_vptr_array; // List of selected DLFLVertex pointers

  DLFLEdgePtrArray sel_eptr_array; // List of selected DLFLEdge pointers
  DLFLFacePtrArray sel_fptr_array; // List of selected DLFLFace pointers
  DLFLFaceVertexPtrArray sel_fvptr_array; // List of selected DLFLFaceVertex pointers

  void clearSelected( ) {
    sel_vptr_array.clear();
    sel_eptr_array.clear();
    sel_fptr_array.clear();
    sel_fvptr_array.clear();
  };

  HashMap faceMap;
  HashMap edgeMap;

  static DLFLVertexPtrArray vparray;                // For selection
  static DLFLEdgePtrArray   eparray;                // For selection
  static DLFLFacePtrArray   fparray;                // For selection
  static DLFLFaceVertexPtrArray fvparray;           // For selection

  Vector3d           position;                      // Position of object
  Vector3d           scale_factor;                  // Scale of object
  Quaternion         rotation;                      // Rotation of object

  inline void removeVertex( DLFLVertexPtr vp ) {
    if (vertex_idx.find(vp) != vertex_idx.end()) vertex_list.erase(vertex_idx[vp]); 
    else vertex_list.remove(vp);
    vertex_idx.erase(vp);
  };
  inline void removeEdge( DLFLEdgePtr ep ) {
    edgeMap.erase(ep->getID());
    if (edge_idx.find(ep) != edge_idx.end()) edge_list.erase(edge_idx[ep]); 
    else edge_list.remove(ep);
    edge_idx.erase(ep);
  };
  inline void removeFace( DLFLFacePtr fp ) {
    faceMap.erase(fp->getID());
    if (face_idx.find(fp) != face_idx.end()) face_list.erase(face_idx[fp]); 
    else face_list.remove(fp);
    face_idx.erase(fp); 
  };

  void computeNormals( );

protected :

  DLFLVertexPtrList          vertex_list;           // The vertex list
  DLFLEdgePtrList            edge_list;             // The edge list
  DLFLFacePtrList            face_list;             // The face list
  DLFLMaterialPtrList        matl_list;             // Material list (for rendering)

  map<DLFLVertexPtr, DLFLVertexPtrList::iterator> vertex_idx;
  map<DLFLFacePtr, DLFLFacePtrList::iterator> face_idx;
  map<DLFLEdgePtr, DLFLEdgePtrList::iterator> edge_idx;
  //TMPatchFacePtrList patch_list;     // List of patch faces
  //int patchsize;         // Size of each patch

  // Below map is for texturing the tiles using Avneet_Ergun method
  std::map<std::string,std::string> TileMapBase;

  uint uID;                                      // ID for this object
  char *mFilename;
  char *mDirname;
  // Assign a unique ID for this instance
  void assignID( ) { uID = DLFLObject::newID(); };

  // Free the memory allocated for the patches
  /*void destroyPatches( ) {
    TMPatchFacePtrList::iterator first = patch_list.begin(), last = patch_list.end();
    TMPatchFacePtr pfp = NULL;
    while ( first != last ) {
      pfp = (*first); ++first;
      delete pfp;
    }
    patch_list.clear();
    };*/

  // Free all the pointers in the lists and clear the lists
  void clearLists( ) {
    clear(vertex_list);
    clear(edge_list);
    clear(face_list);
    clear(matl_list);
    face_idx.clear();
    edge_idx.clear();
    vertex_idx.clear();
    //destroyPatches();
    edgeMap.clear();
    faceMap.clear();
  };

private :

  /// Copy Constructor - make proper copy, don't just copy pointers
  DLFLObject( const DLFLObject& dlfl )
    : position(dlfl.position), scale_factor(dlfl.scale_factor), rotation(dlfl.rotation),
      vertex_list(dlfl.vertex_list), edge_list(dlfl.edge_list), face_list(dlfl.face_list), matl_list(dlfl.matl_list),
      //patch_list(dlfl.patch_list), patchsize(dlfl.patchsize),
      uID(dlfl.uID) {
    for (DLFLVertexPtrList::iterator it = vertex_list.begin();
        it != vertex_list.end(); ++it) vertex_idx[*it] = it;
    for (DLFLEdgePtrList::iterator it = edge_list.begin();
        it != edge_list.end(); ++it) edge_idx[*it] = it;
    for (DLFLFacePtrList::iterator it = face_list.begin();
        it != face_list.end(); ++it) face_idx[*it] = it;
  };

  // Assignment operator
  DLFLObject& operator=( const DLFLObject& dlfl ) {
    position = dlfl.position;
    scale_factor = dlfl.scale_factor;
    rotation = dlfl.rotation;

    // Destroy the existing object
    clearLists();

    // Copy the lists from the new object
    vertex_list = dlfl.vertex_list;
    edge_list = dlfl.edge_list;
    face_list = dlfl.face_list;
    matl_list = dlfl.matl_list;
    //patch_list = dlfl.patch_list;
    //patchsize = dlfl.patchsize;
    for (DLFLVertexPtrList::iterator it = vertex_list.begin();
        it != vertex_list.end(); ++it) vertex_idx[*it] = it;
    for (DLFLEdgePtrList::iterator it = edge_list.begin();
        it != edge_list.end(); ++it) edge_idx[*it] = it;
    for (DLFLFacePtrList::iterator it = face_list.begin();
        it != face_list.end(); ++it) face_idx[*it] = it;
 
    edgeMap = dlfl.edgeMap;
    faceMap = dlfl.faceMap;

    uID = dlfl.uID;
    return (*this);
  };

public :

  // Dump contents of this object
  void dump(ostream& o) const;

  //--- Query Functions ---//

  // Compute the genus of the mesh using Euler formula
  int genus( ) const {
    int v = num_vertices();
    int e = num_edges();
    int f = num_faces();
    int g = 1 - ( v - e +  f )/2;
    return g;
  };

  inline uint getID( ) const { return uID; };
  inline size_t num_vertices( ) const { return vertex_list.size(); };
  inline size_t num_edges( ) const { return edge_list.size(); };
  inline size_t num_faces( ) const { return face_list.size(); };
  inline size_t num_materials( ) const { return matl_list.size(); }

  // Probably should switch to just using these in the future
  // then you could get rid of all these accessors below.
  const DLFLVertexPtrList& getVertexList( ) const { return vertex_list; };
  const DLFLEdgePtrList& getEdgeList( ) const { return edge_list; };
  //const DLFLFacePtrList& getFaceList( ) const { return face_list; };
  DLFLFacePtrList& getFaceList( ) { return face_list; }; // needed not const for subdivideAllFaces

  map<DLFLFacePtr, DLFLFacePtrList::iterator>& getFaceIdx( ) { return face_idx; };
  map<DLFLEdgePtr, DLFLEdgePtrList::iterator>& getEdgeIdx( ) { return edge_idx; };
  map<DLFLVertexPtr, DLFLVertexPtrList::iterator>& getVertexIdx( ) { return vertex_idx; };

  //-- List based access to the 3 lists --//
  DLFLVertexPtr firstVertex( ) { return vertex_list.front(); }
  DLFLEdgePtr firstEdge( ) { return edge_list.front(); }
  DLFLFacePtr firstFace( ) { return face_list.front(); }
  DLFLMaterialPtr firstMaterial( ) { return matl_list.front(); }

  DLFLVertexPtr lastVertex( ) { return vertex_list.back(); };
  DLFLEdgePtr lastEdge( ) { return edge_list.back(); };
  DLFLFacePtr lastFace( ) { return face_list.back(); }
  DLFLMaterialPtr lastMaterial( ) { return matl_list.back(); }

  DLFLVertexPtr findVertex(const uint vid);
  DLFLEdgePtr findEdge(const uint eid);
  DLFLFacePtr findFace(const uint fid);
  DLFLFaceVertexPtr findFaceVertex(const uint fvid );

  DLFLVertexPtrList::iterator beginVertex( ) { return vertex_list.begin(); }
  DLFLVertexPtrList::iterator endVertex( ) { return vertex_list.end(); }

  DLFLEdgePtrList::iterator beginEdge( ) { return edge_list.begin(); }
  DLFLEdgePtrList::iterator endEdge( ) { return edge_list.end(); }

  DLFLFacePtrList::iterator beginFace( ) { return face_list.begin(); }
  DLFLFacePtrList::iterator endFace( ) { return face_list.end(); }

  DLFLMaterialPtrList::iterator beginMaterial( ) { return matl_list.begin(); };
  DLFLMaterialPtrList::iterator endMaterial( ) { return matl_list.end(); };

  DLFLFacePtrList::reverse_iterator rbeginFace( ) { return face_list.rbegin(); }
  DLFLFacePtrList::reverse_iterator rendFace( ) { return face_list.rend(); }

  //--- Access the lists through arrays ---//
  void getVertices(DLFLVertexPtrArray& vparray) {
    vparray.clear(); vparray.reserve(vertex_list.size());
    DLFLVertexPtrList::const_iterator first = vertex_list.begin(), last = vertex_list.end();
    while ( first != last ) {
      vparray.push_back(*first);
      ++first;
    }
  };

  void getEdges(DLFLEdgePtrArray& eparray) {
    eparray.clear(); eparray.reserve(edge_list.size());
    DLFLEdgePtrList::const_iterator first = edge_list.begin(), last = edge_list.end();
    while ( first != last ) {
      eparray.push_back(*first);
      ++first;
    }
  };

  void getFaces(DLFLFacePtrArray& face_array) {
    face_array.clear();
    face_array.reserve(face_list.size());
    for (DLFLFacePtrList::const_iterator it = face_list.begin();
        it != face_list.end(); ++it) {
      face_array.push_back(*it);
    }
  };

  //--- Terminal printing functions : useful for debugging ---//
  void print( ) const {
    // Print a summary of the DLFLObject
    cout << "Number of vertices : " << vertex_list.size() << endl;
    cout << "Number of faces : " << face_list.size() << endl;
    cout << "Number of edges : " << edge_list.size() << endl;
    cout << "Number of materials : " << matl_list.size() << endl;
    cout << "Genus : " << genus() << endl;
  };

  void printVertexList( ) const {
    cout << "Vertex List" << endl;
    DLFLVertexPtrList::const_iterator first = vertex_list.begin(), last = vertex_list.end();
    while ( first != last ) {
      (*first)->print();
      ++first;
    }
  };

  void printEdgeList( ) const {
    cout << "Edge List" << endl;
    DLFLEdgePtrList::const_iterator first = edge_list.begin(), last = edge_list.end();
    while ( first != last ) {
      (*first)->print();
      ++first;
    }
  };

  void printFaceList( ) const {
    cout << "Face List" << endl;
    
    DLFLFacePtrList::const_iterator first = face_list.begin(), last = face_list.end();
    while ( first != last ) {
      cout << *(*first) << endl;
      ++first;
      }
  };
     
  void printFaces( ) const {
    cout << "Faces" << endl;

    DLFLFacePtrList::const_iterator first = face_list.begin(), last = face_list.end();
    while ( first != last ) {
      (*first)->print();
      ++first;
    }
  };
     
  //--- Mutative Functions ---//
  // Reset the whole object
  void reset( ) {
    position.reset(); scale_factor.set(1,1,1); rotation.reset();
    clearLists();
    // Add a default material
    matl_list.push_back(new DLFLMaterial("default",0.5,0.5,0.5));
  };

  void makeVerticesUnique( ) {
    // Make vertices unique
    DLFLVertexPtrList::iterator vfirst=vertex_list.begin(), vlast=vertex_list.end();
    while ( vfirst != vlast ) {
      (*vfirst)->makeUnique();
      ++vfirst;
    }
  };

  void makeEdgesUnique( ) {
    // Make edges unique
    DLFLEdgePtrList::iterator efirst=edge_list.begin(), elast=edge_list.end();
    while ( efirst != elast ) {
      edgeMap.erase((*efirst)->getID());
      (*efirst)->makeUnique();
      edgeMap[(*efirst)->getID()] = (unsigned int)(size_t)(*efirst);
      ++efirst;
    }
  }

  void makeFacesUnique( ) {
    // Make faces unique
    DLFLFacePtrList::iterator ffirst=face_list.begin(), flast=face_list.end();
    while ( ffirst != flast ) {
      faceMap.erase((*ffirst)->getID());
      (*ffirst)->makeUnique();
      faceMap[(*ffirst)->getID()] = (unsigned int)(size_t)(*ffirst);
      ++ffirst;
    }
  };

  void makeUnique( ) {
    assignID();
    makeVerticesUnique();
    makeEdgesUnique();
    makeFacesUnique();
  };

  void destroy( ) {
    // Clear the DLFL structures
    clearLists();
  };

  void assignTileTexEdgeFlags(int n);
  void assignTileTexCoords(int n);
  void randomAssignTexCoords( );

  // Combine two DLFLObject instances into 1 object
  // Lists of second object are cleared. Otherwise when that object is destroyed,
  // pointers in this object will become invalid.
  void splice(DLFLObject& object);

  // Reverse the orientation of all faces in the object
  // This also requires reversing all edges in the object
  void reverse( );

  void addVertex(const DLFLVertex& vertex);         // Insert a copy
  void addVertex(DLFLVertexPtr vertexptr);          // Insert a copy
  void addVertexPtr(DLFLVertexPtr vertexptr) {
    // Insert the pointer.
    // **** WARNING!!! **** Pointer will be freed when list is deleted
    // vertex_list.push_back(vertexptr);
    vertex_idx[vertexptr] = vertex_list.insert(vertex_list.end(), vertexptr);
  };

  void addEdge(const DLFLEdge& edge);               // Insert a copy
  void addEdge(DLFLEdgePtr edgeptr);                // Insert a copy
  void addEdgePtr(DLFLEdgePtr edgeptr) {
    // Insert the pointer.
    // **** WARNING!!! **** Pointer will be freed when list is deleted
    // edge_list.push_back(edgeptr);
    edge_idx[edgeptr] = edge_list.insert(edge_list.end(), edgeptr);
    edgeMap[edgeptr->getID()] = (unsigned int)(size_t)edgeptr;
  };

  void addFace(const DLFLFace& face);               // Insert a copy
  void addFace(DLFLFacePtr faceptr);                // Insert a copy
  void addFacePtr(DLFLFacePtr faceptr) {
    // Insert the pointer.
    // **** WARNING!!! **** Pointer will be freed when list is deleted
    if ( faceptr->material() == NULL )
      // If Face doesn't have a material assigned to it, assign the default material
      faceptr->setMaterial(matl_list.front());
    // face_list.push_back(faceptr);
    face_idx[faceptr] = face_list.insert(face_list.end(), faceptr);
    faceMap[faceptr->getID()] = (unsigned int)(size_t)faceptr;
  };

  DLFLVertexPtr getVertexPtr(uint index) const {
    if ( index >= vertex_list.size() ) return NULL;
    DLFLVertexPtrList::const_iterator i=vertex_list.begin();
    advance(i,index);
    return (*i);
  };
     
  DLFLVertexPtr getVertexPtrID(uint id) const {
    DLFLVertexPtrList::const_iterator first=vertex_list.begin(), last=vertex_list.end();
    DLFLVertexPtr vptr = NULL;
    while (first != last) {
      if ( (*first)->getID() == id ) {
  vptr = (*first);
  break;
      }
      ++first;
    }
    return vptr;
  };

  void updateEdgeList( ) {
    DLFLEdgePtrList::iterator first=edge_list.begin(), last=edge_list.end();
    while ( first != last ) {
      (*first)->updateFaceVertices();
      ++first;
    }
  };

  // Check if an edge exists between two given vertices
  bool edgeExists(DLFLVertexPtr vptr1, DLFLVertexPtr vptr2);

  // Check if an edge exists between vertices given by two corners
  // Simply calls above function
  inline bool edgeExists(DLFLFaceVertexPtr fvptr1, DLFLFaceVertexPtr fvptr2) {
    return edgeExists(fvptr1->vertex,fvptr2->vertex);
  };

  // Check if a given edge exists in the edge list. If it does pointer is set to that edge
  bool edgeExists(const DLFLEdge& e, DLFLEdgePtr& eptr) {
    DLFLEdgePtrList::iterator first=edge_list.begin(), last=edge_list.end();
    while ( first != last ) {
      if ( (*(*first)) == e ) {
        eptr = *first;
        return true;
      }
      ++first;
    }
    eptr = NULL;
    return false;
  };

  void addEdges(DLFLEdge * edges, int num_edges) {
    DLFLEdgePtr eptr;
  
    for (int i=0; i < num_edges; ++i) {
      if ( edgeExists(edges[i],eptr) == false ) {
        addEdge(edges[i]);
      } else {
        // If Edge already exists, then the second FaceVertexPtr in the Edge must
        // be changed to that from the new Edge with the same ID as the second one
        // in this Edge
        int id2 = (eptr->getFaceVertexPtr2())->getVertexID();
        int eid1 = (edges[i].getFaceVertexPtr1())->getVertexID();

        if (eid1 == id2) eptr->setFaceVertexPtr2(edges[i].getFaceVertexPtr1());
        else eptr->setFaceVertexPtr2(edges[i].getFaceVertexPtr2());
      }
      eptr = NULL;
    }
  };

  void addEdgesWithoutCheck(DLFLEdge * edges, int num_edges) {
    for (int i=0; i < num_edges; ++i)
      addEdge(edges[i]);
  };

  void updateFaceList( ) {
    DLFLFacePtrList::iterator first=face_list.begin(), last=face_list.end();
    while (first != last) {
      (*first)->updateFacePointers();
      (*first)->addFaceVerticesToVertices();
      ++first;
    }
  };

  DLFLFacePtrArray createFace(const Vector3dArray& verts, DLFLMaterialPtr matl = NULL, bool set_type = false);

  DLFLFaceVertexPtr createPointSphere(const Vector3d& v, DLFLMaterialPtr matl = NULL );
  void removePointSphere( DLFLFaceVertexPtr fvp );

  // Compute the bounding box for this object
  void boundingBox(Vector3d& min, Vector3d& max) const;
  bool boundaryWalkID( uint faceId );
  void walk( uint faceId, vector<int> &verts, vector<int> &edges );
  //vector<int> vertWalk( uint faceId );
  //vector<int> edgeWalk( uint faceId );
  void boundaryWalk(uint face_index);
  void vertexTrace(uint vertex_index);

  void readObject( istream& i, istream &imtl = *static_cast<istream*>(NULL));
  void readObjectAlt( istream& i );
  void fromData(Vector3d *vertices, int vertex_count, uint* face_index, int face_count);
  void readDLFL( istream& i, istream &imtl = *static_cast<istream*>(NULL), bool clearold = true );
  bool readMTL( istream &i);
  bool writeMTL( ostream& o );
  
  void writeObject( ostream& o, ostream &omtl = *static_cast<ostream*>(NULL), bool with_normals = true, bool with_tex_coords = true );
  void writeDLFL(ostream& o, ostream &omtl = *static_cast<ostream*>(NULL), bool reverse_faces = false);
  void writeSTL(ostream& o);
  void writeLG3d(ostream& o, bool select = false); //!< added by dave - for LiveGraphics3D support to embed 3d models into html
  inline void setFilename( const char *filename ) { 
    // if( mFilename) { delete [] mFilename; mFilename = NULL; }
    // mFilename = filename; 
     if ( filename ) {
        mFilename = new char[strlen(filename)+1]; strcpy(mFilename,filename);
      } else {
        mFilename = new char[8]; strcpy(mFilename,"default");
      }
  };
  inline char* getFilename( ) { return mFilename; }
  
  inline void setDirname( const char *dirname ) { 
     if ( dirname ) {
        mDirname = new char[strlen(dirname)+1]; strcpy(mDirname,dirname);
      } else {
        mDirname = new char[3]; strcpy(mDirname,"$HOME");
      }
  };

  DLFLMaterialPtr findMaterial( const RGBColor& color ) {
    DLFLMaterialPtr matl = NULL;
    DLFLMaterialPtrList::iterator first, last;
    first = matl_list.begin(); last = matl_list.end();
    while ( first != last ) {
      if ( (*first)->equals(color) ) {
        matl = (*first); break;
      }
      ++first;
    }

    return matl;
  };

  DLFLMaterialPtr findMaterial( const char *mtlname ) {
    DLFLMaterialPtr matl = NULL;
    DLFLMaterialPtrList::iterator first, last;
    first = matl_list.begin(); last = matl_list.end();
    while ( first != last ) {
      if ( mtlname && !strcasecmp((*first)->name,mtlname) ) {
        matl = (*first); break;
      }
      ++first;
    }
    return matl;
  };

  void clearMaterials(){
    //iterate through faces...
    // DLFLMaterialPtr mptr = new DLFLMaterial("default",0.5,0.5,0.5);
    // setColor(RGBColor(0.5,0.5,0.5));
    
    DLFLFacePtrList::iterator ffirst=face_list.begin(), flast=face_list.end();
    while ( ffirst != flast ) {
      (*ffirst)->setMaterial(matl_list.front());
      ++ffirst;
    }    
    //clear materials
    while (matl_list.size() > 1){
      // if ( !( (*matl_list.back()) == mptr) ) {
      matl_list.pop_back();
      // }
    }
    //add the fresh blank gray material
    // matl_list.push_back(mptr);
  }

  DLFLMaterialPtr addMaterial(RGBColor color){
    //first search for the material to see if it exists already or not
    char matl_name[10];
    DLFLMaterialPtr mtl = findMaterial(color);
    
    // No matching material found
    if ( mtl == NULL ) {
      //add this as a new material
      sprintf(matl_name,"material%d",matl_list.size());
      matl_list.push_back(new DLFLMaterial(matl_name,color));
      mtl = matl_list.back();
      return mtl;
    } 
    else {
      //it already exists... return it
      return mtl;
    }    
  }

  void setColor( const RGBColor& col ) {
    // matl_list[0] is always the default material
    matl_list.front()->setColor(col);
  };

  //-- Geometric Transformations --//
  
  // Freeze any stored transformations and reset the transformations
  // Order of application : rotation, scale, translate
  void freezeTransformations(void) {
    tr.reset();
    tr.scale(scale_factor);
    tr.rotate(rotation);
    tr.translate(position);
    Matrix4x4 tmat = tr.matrix();
    DLFLVertexPtrList :: iterator vfirst = vertex_list.begin(), vlast = vertex_list.end();
    DLFLVertexPtr vp;
    while ( vfirst != vlast ) {
      vp = (*vfirst); ++vfirst;
      vp->transform(tmat);
    }
  }

  // Apply GL transformations before rendering
  void transform(void) const {
    tr.reset();
    tr.scale(scale_factor);
    tr.rotate(rotation);
    tr.translate(position);
    tr.apply();
  }

  // Apply the transformations for this object on the given vector
  void transform(Vector3d& p) {
    tr.reset();
    tr.scale(scale_factor);
    tr.rotate(rotation);
    tr.translate(position);
    Vector4d tp(p); tp[3] = 1.0;
    tp = tr.matrix() * tp;
    tp /= tp[3];
    p = tp;
  }

};
  // Build the list of patch faces
  /*void createPatches() {
    destroyPatches();
    DLFLFacePtrList::iterator ffirst = face_list.begin(), flast = face_list.end();
    DLFLFacePtr fp = NULL;
    TMPatchFacePtr pfp = NULL;
       
    while ( ffirst != flast ) {
      fp = (*ffirst); ++ffirst;
      pfp = new TMPatchFace(patchsize);
      pfp->setDLFLFace(fp); pfp->createPatches();
      patch_list.push_back(pfp);
      }

    // Adjust the edge points for all patches
    DLFLEdgePtrList::iterator efirst = edge_list.begin(), elast = edge_list.end();
    DLFLEdgePtr ep = NULL;
    DLFLFaceVertexPtr fvp1,fvp2;
    TMPatchPtr pp1, pp2;
    Vector3d p00,p01,p10,p11,ip;
    while ( efirst != elast ) {
      ep = (*efirst); ++efirst;
      ep->getCorners(fvp1,fvp2);
      pp1 = fvp1->getPatchPtr(); pp2 = fvp2->getPatchPtr();
      
      p00 = pp1->getControlPoint(2,0); p01 = pp2->getControlPoint(2,0);
      p10 = pp1->getControlPoint(3,1); p11 = pp2->getControlPoint(3,1);
      ip = intersectCoplanarLines(p00,p01,p10,p11);
      
      pp1->setControlPoint(3,0,ip); pp2->setControlPoint(3,0,ip);
      pp1->updateGLPointArray(); pp2->updateGLPointArray();
      
      pp1 = fvp1->next()->getPatchPtr(); pp2 = fvp2->next()->getPatchPtr();
      pp1->setControlPoint(0,3,ip); pp2->setControlPoint(0,3,ip);
      pp1->updateGLPointArray(); pp2->updateGLPointArray();
    }
    
    // Adjust the vertex points for 4-valence vertices
    DLFLVertexPtrList::iterator vfirst = vertex_list.begin(), vlast = vertex_list.end();
    DLFLVertexPtr vp = NULL;
    while ( vfirst != vlast ) {
      vp = (*vfirst); ++vfirst;
      if ( vp->valence() == 4 ) {
  DLFLFaceVertexPtrArray vcorners;
  vp->getOrderedCorners(vcorners);
  pp1 = vcorners[0]->getPatchPtr(); pp2 = vcorners[2]->getPatchPtr();

  p00 = pp1->getControlPoint(1,0); p01 = pp2->getControlPoint(1,0);
  p10 = pp1->getControlPoint(0,1); p11 = pp2->getControlPoint(0,1);
  ip = intersectCoplanarLines(p00,p01,p10,p11);

  for (int i=0; i < 4; ++i) {
    pp1 = vcorners[i]->getPatchPtr();
    pp1->setControlPoint(0,0,ip);
    pp1->updateGLPointArray();
  }
      }
    }
    }
  };*/
} // end namespace
#endif /* _DLFL_OBJECT_HH_ */
