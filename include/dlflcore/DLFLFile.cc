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

#include "DLFLObject.hh"
#include <cstdio>
#include <cstring>

namespace DLFL {

	typedef vector<Vector3d> Vector3dArray;
	typedef vector<Vector2d> Vector2dArray;

	// Temporary array to store the vertices and face vertices
	static DLFLVertexPtrArray vertex_array;
	static DLFLFaceVertexPtrArray face_vertex_array;
	static Vector3dArray normals;
	static Vector2dArray texcoords;


	static char *dname;

    void DLFLObject::fromData(Vector3d *vertices, int vertex_count, uint* face_index, int face_count) {
        /*
         * this function does not cover material information
        */
        // Clear the object first
        reset();
        vertex_array.clear();
        DLFLVertexPtr newvptr;
        DLFLFaceVertexPtr newfvptr;
        DLFLFacePtr newfptr;
        DLFLEdge * edges = NULL;
        int num_edges=0;

        for (int i = 0; i < vertex_count; ++i) {
            // Create a new DLFLVertex
            newvptr = new DLFLVertex( vertices[i] );
            // Add the pointer to the VertexPtr list. The list will free the memory
            addVertexPtr(newvptr);
            // Add the pointer to the local vertex_array
            // for easy access when creating the faces
            vertex_array.push_back(newvptr);
        }

        for (int i = 0; i < face_count; ++i) {
            // Create a new DLFLFace
            newfptr = new DLFLFace;
            for (int j = 0; j < 4; ++j) {
                // Create a new DLFLFaceVertex
                newfvptr = new DLFLFaceVertex;
                // Set the Vertex ptr field for the new face vertex
                int v = face_index[4*i + j] - 1; //minus 1 is because the face indices start with 1 based on OBJ file format
                newfvptr->vertex = vertex_array[v];
                newfptr->addVertexPtr(newfvptr);
                //set the normal of the vertex
                int before(0), next(0);
                if (j == 0) {
                    before = face_index[4*i + 3] - 1;
                }
                else {
                    before = face_index[4*i + j - 1] - 1;
                }
                if (j==3) {
                    next = face_index[4*i] - 1;
                }
                else {
                    next = face_index[4*i + j + 1] - 1;
                }
                Vector3d v_next = vertices[next] - vertices[v];
                Vector3d v_before = vertices[before] - vertices[v];
                Vector3d n = v_next % v_before;
                double sqrLength = n.lengthsqr();
                if (sqrLength != 0) {
                    double length = sqrt(sqrLength);
                    n/=length;
                }
                newfvptr->setNormal(n);
            }



            // Add new face to the face list
            addFacePtr(newfptr);
            // Get the edges from the new face
            num_edges = newfptr->getEdges(&edges);
            // Add the edges from the new face
            addEdges(edges,num_edges);
            // Delete the Edge array allocated by getEdges, since addEdges makes a copy
            delete [] edges; edges = NULL;

            // fix the face vertex normals
//            DLFLFacePtrList::iterator begin = this->beginFace();
//            DLFLFacePtrList::iterator end = this->endFace();

//            while (begin != end) {
//                DLFLFacePtr faceptr = *begin;
//                faceptr->facevertex();
//                DLFLFaceVertexPtr first = faceptr->firstVertex();
//                faceptr->lastVertex();


//                begin++;
//            }

        }
        // Clear the temporary vertex array
        vertex_array.clear();
        // Make all Vertexes, Edges and Faces unique
        makeUnique();
        // update all the EdgePtr fields for the Faces through the Edges
        updateEdgeList();
        // update all the FacePtr fields for the FaceVertexes through the Faces
        updateFaceList();
    }


	void DLFLObject::readObject(istream& i, istream &imtl) {
		// std::cout << "reading obj file \n";
		if ( !i ) {
			cerr  << "Incomplete OBJ file." << endl;
			return;
		}

		// Clear the object first
		reset();

		DLFLVertexPtr newvptr;
		DLFLFaceVertexPtr newfvptr;
		DLFLFacePtr newfptr;
		DLFLMaterialPtr cur_mtl = matl_list.front();
		DLFLEdge * edges = NULL;
		RGBColor color;
		bool matl_added = false;
		char matl_name[10];
		Vector3d xyz;
		Vector2d uv;
		char c,c2;
		int num_edges=0;

		// char *tmp = new char[512];
		// strcpy( tmp, filename );
		// dname = dirname( tmp );
		// Get file size
		// fseek( fp, 0, SEEK_END );
		// long lSize = ftell( fp );
		// rewind( fp );
		// allocate memory
		// char *buffer = new char[lSize];
		// if( buffer == NULL ) return false;
		// load the file into the buffer
		// fread( buffer, 1, lSize, fp );

		// long i = 0;
		// int currentMaterial = -1;

		// Read each line and set the Vertex, Normal, Face, Color or Texture
		while ( i ) {
			removeWhiteSpace(i); i.get(c); i.get(c2);
			if ( c == 'm' && c2 == 't'){
				char mtlfilename[256], mtlfilepath[512];
				i.get(c); i.get(c2); i.get(c); i.get(c2); i.get(c2);
				i >> mtlfilename;
				// std::cout << mtlfilename << "\n";
				// sprintf( mtlfilepath, "%s/%s", mDirname, mtlfilename );
				// std::cout << mtlfilepath << "\n";
				// ifstream file;
				// file.open(mtlfilepath);
				readMTL(imtl);
			}
			else if (c == 'u' && c2 == 's'){
				i.get(c);i.get(c);i.get(c);i.get(c);i.get(c);
				char *mtlname = new char[256];
				i >> mtlname;
				cur_mtl = findMaterial(mtlname);
				// std::cout << mtlname << "\t" << cur_mtl->name << "\n";
			}
			else if ( c == 'c' && c2 == ' ' ) {
				// Read a color specification
				i >> color; cur_mtl = findMaterial(color);
				if ( cur_mtl == NULL ) {                     // No matching material found
					if (matl_added == false) {
						// No new materials have been added.
						// Set default material to be this color
						setColor(color); matl_added = true;
						cur_mtl = matl_list.front();
					} 
					else {
						// Atleast 1 new material was added, but none of the
						// existing materials match this color. So create a new
						// material with this color and add it to the list
						sprintf(matl_name,"material%d",matl_list.size());
						matl_list.push_back(new DLFLMaterial(matl_name,color));
						cur_mtl = matl_list.back();
					}
				}
			} 
			else if ( c == 'v' ) {
				if ( c2 == ' ' ) {
					// Read a vertex specification
					i >> xyz;
					// Create a new DLFLVertex
					newvptr = new DLFLVertex( xyz );
					// Add the pointer to the VertexPtr list. The list will free the memory
					addVertexPtr(newvptr);
					// Add the pointer to the local vertex_array
					// for easy access when creating the faces
					vertex_array.push_back(newvptr);
				} 
				else if ( c2 == 'n' ) {
					// Read a normal specification
					i >> xyz; 
					normals.push_back(xyz);
				} 
				else if ( c2 == 't' ) {
					// Read a texture coordinate
					i >> uv;
					texcoords.push_back(uv);
				}
			} 
			else if ( c == 'f' && c2 == ' ' ) {
				// Create a new DLFLFace
				newfptr = new DLFLFace;
				// Read a face specification
				c = i.peek(); 
				while ( c != '\n' ) {
					int v,vt,vn;
					i >> v; vt = -1; vn = -1; c = i.peek();
					if ( c == '/' ) {
						i.get(c); c = i.peek();
						if ( c != '/' )  i >> vt; c = i.peek();
						
						if ( c == '/' ) i.get(c); i >> vn; c = i.peek();
					}
					// We have v,vt and vn now
					// Create a new DLFLFaceVertex
					newfvptr = new DLFLFaceVertex;
					// Set the Vertex ptr field for the new face vertex
					newfvptr->vertex = vertex_array[v-1];
					if ( vt > 0 ) newfvptr->texcoord = texcoords[vt-1];
					if ( vn > 0 ) newfvptr->normal = normals[vn-1];
					// Add this new DLFLFaceVertexPtr to the new DLFLFace
					newfptr->addVertexPtr(newfvptr);
				}
				// Set material for new face to be current material and
				// add pointer to new face to current material
				// std::cout << "cur_mtl->color = " << cur_mtl->color << "\n";
				newfptr->setMaterial(cur_mtl);
				
				// Add new face to the face list
				addFacePtr(newfptr);
				// Get the edges from the new face
				num_edges = newfptr->getEdges(&edges);
				// Add the edges from the new face
				addEdges(edges,num_edges);
				// Delete the Edge array allocated by getEdges, since addEdges makes a copy
				delete [] edges; edges = NULL;
			}
			if ( c2 != '\n' ) readTillEOL(i);
		}

		// Clear the temporary vertex array
		vertex_array.clear();
		// Make all Vertexes, Edges and Faces unique
		makeUnique();
		// update all the EdgePtr fields for the Faces through the Edges
		updateEdgeList();
		// update all the FacePtr fields for the FaceVertexes through the Faces
		updateFaceList();
		
		// std::cout << "done reading obj\n;";
	}

	void DLFLObject::writeObject(ostream& o, ostream &omtl, bool with_normals, bool with_tex_coords) {
		//write mtl file
		if (!omtl.fail())
			writeMTL(omtl);
		
		// Write out the DLFL object as an OBJ file into the given output stream
		o << "mtllib " << mFilename << ".mtl\n";

		// First make the Position ID's unique for the VertexList so Vertex IDs will
		// be contiguous and monotonically increasing
		// Don't Do this, that way the IDs stay the same
		for_each(vertex_list.begin(),vertex_list.end(),makeVertexUnique);

		// Get the Position ID for the first Vertex in the list
		// -1 is because OBJ file indices start at 1 and not 0
		uint min_id = vertex_list.front()->getID() - 1;

		// Output the Vertex list
		DLFLVertexPtrList::const_iterator vf = vertex_list.begin(), vl = vertex_list.end();
		while ( vf != vl ) {
			o << *(*vf);
			++vf;
		}

		o << "# " << vertex_list.size() << " vertices" << endl << endl;

		DLFLFacePtrList::const_iterator ff, fl = face_list.end();

		if ( with_normals ) {
			ff = face_list.begin();
			// Output the normals for each FaceVertex in each Face
			while ( ff != fl ) {
				(*ff)->objWriteNormals(o);
				++ff;
			}
		}
		if ( with_tex_coords ) {
			ff = face_list.begin();
			// Output the texture coordinates for each FaceVertex in each Face
			while ( ff != fl ) {
				(*ff)->objWriteTexCoords(o);
				++ff;
			}
		}
		ff = face_list.begin();
		DLFLMaterialPtr mptr = (*ff)->material();
		o << "usemtl " << mptr->name << "\n";						
		
		if ( with_normals ) {
			uint normal_id_start = 1;
			if ( with_tex_coords ) {
				// Output the Face list with normals and texture coords
				uint tex_id_start = 1;
				while ( ff != fl ) {
					if (mptr != (*ff)->material()){
						mptr = (*ff)->material();
						o << "usemtl " << mptr->name << "\n";						
					}
					(*ff)->objWriteWithNormalsAndTexCoords(o,min_id,normal_id_start,tex_id_start);
					++ff;
				}
			} 
			else {
				// Output the Face list with normals only
				while ( ff != fl ) {
					if (mptr != (*ff)->material()){
						mptr = (*ff)->material();
						o << "usemtl " << mptr->name << "\n";						
					}
					
					(*ff)->objWriteWithNormals(o,min_id,normal_id_start);
					++ff;
				}
			}
		}
		else if ( with_tex_coords ) {
			// Output the face list with texture coords but without normals
			uint tex_id_start = 1;
			while ( ff != fl ) {
				if (mptr != (*ff)->material()){
					mptr = (*ff)->material();
					o << "usemtl " << mptr->name << "\n";						
				}
				
				(*ff)->objWriteWithTexCoords(o,min_id,tex_id_start);
				++ff;
			}
		} 
		else {
			// Output the Face list without normals or texture coordinates
			while ( ff != fl ) {
				if (mptr != (*ff)->material()){
					mptr = (*ff)->material();
					o << "usemtl " << mptr->name << "\n";						
				}				
				(*ff)->objWrite(o,min_id);
				++ff;
			}
		}

		o << "# " << face_list.size() << " faces" << endl << endl;
	}//end write object function

	void DLFLObject::readDLFL(istream& i, istream &imtl,  bool clearold) {
		// Read the object from an input stream in DLFL format
		// std:: cout << "about to read dlfl" << i << endl;
		if ( !i ) {
			cerr  << "Incomplete DLFL file." << endl;
			return;
		}

		// Clear the object first if flag is set
		// Otherwise new vertices,faces and edges will be appended to the existing lists
		if ( clearold ) reset();

		DLFLVertexPtr newvptr;
		DLFLFaceVertexPtr newfvptr, fvptr;
		DLFLEdgePtr neweptr;
		DLFLFacePtr newfptr;
		DLFLMaterialPtr cur_mtl = matl_list.front();
		Vector3d xyz;
		char c,c2;
		uint vindex, fvindex, fvindex1, fvindex2;

		// First line of the file should be "DLFL"
		const char dlfl[] = "DLFL";
		char compare[4];
		i.read(compare,4);
		if( strncmp(dlfl,compare,4) != 0 ) {
			cerr << "File not in DLFL format" << endl;
			return;
		}
		readTillEOL(i); c = ' ';

		//read the material
		while ( i && c != '#' ) {
			i.get(c); i.get(c2);
			if ( c == 'm' && c2 == 't'){
				readTillEOL(i); 
				// char *mtlfilename = new char[256];//, mtlfilepath[512];
				// i.get(c); i.get(c2); i.get(c); i.get(c2); i.get(c2);
				// i >> mtlfilename;
				// std::cout << mtlfilename << "\n";
				// sprintf( mtlfilepath, "%s/%s", mDirname, mtlfilename );
				// std::cout << mtlfilepath << "\n";
				// ifstream file;
				// file.open(mtlfilepath);
				readMTL(imtl);
				// file.close()
			}
		}
		
		if ( !i ) {
			cerr << "Incomplete DLFL file. Failed after mtl read." << endl;
			reset();
			return;
		}
		
		if ( c2 != '\n' ) readTillEOL(i);
		c = ' ';
		
		// Read the vertices first. Stop when we get to a '#' sign at the beginning of a line
		while ( i && c != '#' ) {
			i.get(c); i.get(c2);
			if ( c == 'v' && c2 == ' ') {
				// Read a vertex specification
				// std::cout << "reading a vertex\n";
				
				i >> xyz; readTillEOL(i);

				// Create a new DLFLVertex
				newvptr = new DLFLVertex(xyz);

				// Add the pointer to the VertexPtr list. The list will free the memory
				addVertexPtr(newvptr);

				// Add the pointer to the local vertex_array
				// for easy access when creating the face vertices
				vertex_array.push_back(newvptr);
			}
		}

		if ( !i ) {
			cerr << "Incomplete DLFL file. Failed after vertices." << endl;
			reset();
			return;
		}

		// Read the face vertices next. Stop when we get to a '#' sign at the beginning of a line
		if ( c2 != '\n' ) readTillEOL(i);
		c = ' ';
		while ( i && c != '#') {
			i.get(c); i.get(c2);
			if ( c == 'f' && c2 == 'v' ) {
				// std::cout << "reading a face vertex\n";
				
				// Read a face vertex specification
				newfvptr = new DLFLFaceVertex;

				vindex = newfvptr->readDLFL(i); readTillEOL(i);
				newfvptr->vertex = vertex_array[vindex];

				// Add the pointer to the local face_vertex_array
				// for eash access when creating the faces and edges
				face_vertex_array.push_back(newfvptr);
			}
		}

		if ( !i ) {
			cerr << "Incomplete DLFL file. failed after Face-vertices" << endl;
			reset();
			return;
		}

		// Read the edges next. Stop when we get to a '#' sign at the beginning of a line
		if ( c2 != '\n' ) readTillEOL(i);

		c = ' ';
		while ( i && c != '#') {
			i.get(c); i.get(c2);
			if ( c == 'e' && c2 == ' ' ) {
				// Read a edge specification
				// std::cout << "reading an edge\n";
				neweptr = new DLFLEdge;
				i >> fvindex1 >> fvindex2; readTillEOL(i);
				// Set the ends of the edge using the face vertex array
				neweptr->setFaceVertexPointers(face_vertex_array[fvindex1],face_vertex_array[fvindex2],false);
				// Update the EdgePtr fields of the face vertices
				neweptr->updateFaceVertices();
				// Add the edge to the edge list
				addEdgePtr(neweptr);
			}
		}

		if ( !i ) {
			cerr << "Incomplete DLFL file. Failed after edges." << endl;
			reset();
			return;
		}

			// Read the faces next. Stop when we get to a '#' sign at the beginning of a line
		if ( c2 != '\n' ) readTillEOL(i);
		c = ' ';
		while ( i && c != '#') {
			i.get(c); i.get(c2);
			if (c == 'u' && c2 == 's'){
				i.get(c);i.get(c);i.get(c);i.get(c);i.get(c);
				char *mtlname = new char[256];
				i >> mtlname;
				cur_mtl = findMaterial(mtlname);
				// std::cout << mtlname << "\t" << cur_mtl->name << "\n";
				readTillEOL(i);
			}
			else if ( c == 'f' && c2 == ' ' )	{
				
				// std::cout << "reading a face\n";
					// Read a face specification
				newfptr = new DLFLFace;

					// Read a face specification. Get the face vertex index and find
					// the face vertex pointer from the array and add it to the face
				c = i.peek(); 
				while ( c != '\n' )
				{
					i >> fvindex;
					fvptr = face_vertex_array[fvindex];
					newfptr->addVertexPtr(fvptr);
					c = i.peek();
				}
				readTillEOL(i);

				// Set material for new face to be current material and
				// add pointer to new face to current material
				newfptr->setMaterial(cur_mtl);

				// Update the FacePtr fields of the face vertices
				// and add the face vertices to the face vertex list of vertices
				newfptr->updateFacePointers();
				newfptr->addFaceVerticesToVertices();

				// Add the face to the face list
				addFacePtr(newfptr);
			}
		}

		// Clear the temporary vertex array and face vertex array
		vertex_array.clear();
		face_vertex_array.clear();
		assignID();

		// Make all Vertexes, Edges and Faces unique
		makeUnique();
		
		// printVertexList();
		// printFaceList();
		// // printFaceVertexList();
		// printEdgeList();
	}

	void DLFLObject::writeDLFL(ostream& o, ostream &omtl, bool reverse_faces) {
		//write the mtl file if it exists
		if (!omtl.fail()){
			// std::cout<<"mtl file did not fail.\n";
			writeMTL(omtl);	
		}
		// Write the object in DLFL format into give output stream
		// Write marker at beginning indicating DLFL format
		o << "DLFL" << endl;
		o << "mtllib " << mFilename << ".mtl" << endl;
		o << '#' << endl;

		// std::cout << "writing dlfl\t" << mFilename << "\n";
		
		// Write the vertex list next. Update the vertex index also
		DLFLVertexPtrList::iterator vf = vertex_list.begin(), vl = vertex_list.end();
		uint vindex = 0;
		while ( vf != vl ) {
			(*vf)->writeDLFL(o,vindex++);
			++vf;
		}
		o << '#' << endl;

		// Write the face vertices and update the face vertex index also
		DLFLFacePtrList::iterator ff = face_list.begin(), fl = face_list.end();		
		DLFLFacePtr fptr;
		uint fvindex = 0;
		while ( ff != fl ) {
			fptr = (*ff);
			DLFLFaceVertexPtr head;
			head = fptr->front();
			if ( head ) {
				DLFLFaceVertexPtr current = head;
				current->writeDLFL(o,fvindex++);
				current = current->next();
				while ( current != head ) {
					current->writeDLFL(o,fvindex++);
					current = current->next();
				}
			}
			++ff;
		}
		o << '#' << endl;

		// Write the edge list
		DLFLEdgePtrList::iterator ef = edge_list.begin(), el = edge_list.end();
		if ( reverse_faces ) {
			while ( ef != el ) {
				(*ef)->writeDLFLReverse(o);
				++ef;
			}
		}
		else {
			while ( ef != el ) {
				(*ef)->writeDLFL(o);
				++ef;
			}
		}

		o << '#' << endl;
        DLFLMaterialPtr mptr = nullptr;//(*ff)->material();
		// o << "usemtl " << mptr->name << "\n";						
		// Write the face list
		ff = face_list.begin(); fl = face_list.end();
		if ( reverse_faces ) {
			while ( ff != fl ) {
				if (mptr != (*ff)->material()){
					mptr = (*ff)->material();
					o << "usemtl " << mptr->name << "\n";						
				}				
				(*ff)->writeDLFLReverse(o);
				++ff;
			}
		}
		else {
			while ( ff != fl ) {
				if (mptr != (*ff)->material()){
					mptr = (*ff)->material();
					o << "usemtl " << mptr->name << "\n";						
				}				
				(*ff)->writeDLFL(o);
				++ff;
			}
		}
		o << '#' << endl;
	}

	bool DLFLObject::readMTL( istream &i ) {
		char c,c2;
		float r,g,b;
		if ( !i ) {
			cerr  << "Incomplete MTL file." << endl;
			return false;
		}
		// RGBColor color;
		DLFLMaterialPtr mptr;
		char *mtlname = new char[255];
		
		while ( i ) {
			removeWhiteSpace(i); i.get(c); i.get(c2);
			if ( c == 'n' && c2 == 'e'){
				i.get(c); i.get(c2); i.get(c); i.get(c2); i.get(c2);
				i >> mtlname; 
			}
			else if (c == 'K' && c2 == 'd'){
				i.get(c);
				i >> r >> g >> b;
				DLFLMaterialPtr mptr = new DLFLMaterial(mtlname,r,g,b);
				matl_list.push_back(mptr);
			}
			if ( c2 != '\n' ) readTillEOL(i);
		}
		return true;
	}
	
	bool DLFLObject::writeMTL( ostream& o ) {

		// newmtl blinn1SG
		// illum 4
		// Kd 0.06 0.50 0.03
		// Ka 0.00 0.00 0.00
		// Tf 1.00 1.00 1.00
		// Ni 1.00
		// Ks 0.50 0.50 0.50
		// newmtl initialShadingGroup
		// illum 4
		// Kd 0.50 0.50 0.50
		// Ka 0.00 0.00 0.00
		// Tf 1.00 1.00 1.00
		// Ni 1.00
		if (o){
			//test by dave...
			//store the material color in the diffuse channel
			DLFLMaterialPtrList::const_iterator mf = matl_list.begin(), ml = matl_list.end();
			while ( mf != ml ) {
				o <<  "newmtl " << (*mf)->name << "\n"
					<< "illum 4\n" 
					<< "Kd " << (*mf)->color.r << " " << (*mf)->color.g << " " << (*mf)->color.b << "\n" 
					<< "Ka 0.00 0.00 0.00\n" 
					<< "Tf 1.00 1.00 1.00\n"
					<< "Ni 1.00\n"
					<< "Ks 0.00 0.00 0.00\n";
				++mf;
			}
		}
		else{
			// std::cout << "not valid mtl filestream\n";
			return false;
		}
		return true;
		
	}

	void DLFLObject::writeLG3d(ostream& o, bool selected) {

		Vector3dArray coords; int i=0, j=0;		
		if (selected){
			vector<DLFLFacePtr>::iterator ff = this->sel_fptr_array.begin(), 
																		fl = this->sel_fptr_array.end();
			// Write the object in LG3d (*.m) format for use with the LiveGraphics3D live.jar java archive from Mathworld.com
			o << "Graphics3D[{";

			while ( ff != fl ) {
				//format: Polygon[{ {x,y,z}, {x,y,z}, {x,y,z}, {x,y,z} }],
				o << "Polygon[{";
				(*ff)->getVertexCoords(coords);
				for (i=0; i < coords.size(); i++){
					o << "{" << coords[i][0] << "," << coords[i][1] << "," << coords[i][2] << "}"; 
					if (i != coords.size()-1){
						o << ",";
					}
				}
				o << "}]";
				if ( j < num_faces()-1){
					o << ",";
				}
				++ff; j++;
			}
			//close out the file and make sure it doesn't have a "box" around it
			o << "}, { Boxed -> False }]";
			
		}
		else {
			DLFLFacePtrList::iterator ff, fl;
			ff = face_list.begin(); 
			fl = face_list.end();
			// Write the object in LG3d (*.m) format for use with the LiveGraphics3D live.jar java archive from Mathworld.com
			o << "Graphics3D[{";

			while ( ff != fl ) {
				//format: Polygon[{ {x,y,z}, {x,y,z}, {x,y,z}, {x,y,z} }],
				o << "Polygon[{";
				(*ff)->getVertexCoords(coords);
				for (i=0; i < coords.size(); i++){
					o << "{" << coords[i][0] << "," << coords[i][1] << "," << coords[i][2] << "}"; 
					if (i != coords.size()-1){
						o << ",";
					}
				}
				o << "}]";
				if ( j < num_faces()-1){
					o << ",";
				}
				++ff; j++;
			}
			//close out the file and make sure it doesn't have a "box" around it
			o << "}, { Boxed -> False }]";
		}
	}
	
	void DLFLObject::writeSTL(ostream& o){		
		// if(binary)
		// {
		// 	// Write Header
		// 	char *header="VCG                                                                                                  ";
		// 	if(objectname)	strncpy(header,objectname,80);
		// 	fwrite(header,80,1,fp);
		// 	// write number of facets
		// 	fwrite(&m.fn,1,sizeof(int),fp); 
		// 	Point3f p;
		// 	unsigned short attributes=0;
		//     
		//     FaceIterator fi;		
		// 	for(fi=m.face.begin(); fi!=m.face.end(); ++fi) if( !(*fi).IsD() )
		// 	{
		// 		// For each triangle write the normal, the three coords and a short set to zero
		// 		p.Import(vcg::NormalizedNormal(*fi));
		// 		fwrite(p.V(),3,sizeof(float),fp);
		//  
		// 		for(int k=0;k<3;++k){
		// 			p.Import((*fi).V(k)->P());
		// 			fwrite(p.V(),3,sizeof(float),fp);
		// 		}
		// 		fwrite(&attributes,1,sizeof(short),fp);
		// 	}
		// }
		// else
		// {
			DLFLFacePtrList::iterator ff = face_list.begin(); 
			DLFLFacePtrList::iterator fl = face_list.end();
			Vector3dArray coords; int i=0;
			
			o << "solid ascii\n";
			while ( ff != fl ) {
				o << "  facet normal "	<< (*ff)->getNormal(true)[0] << " "  << (*ff)->getNormal()[1] << " " << (*ff)->getNormal()[2] << "\n";
				o << "    outer loop\n";	
				(*ff)->getVertexCoords(coords);
				for (i=0; i < coords.size(); i++){
					o << "      vertex  " << coords[i][0] << " " << coords[i][1] << " " << coords[i][2] << "\n"; 
				}
				o << "    endloop\n";
				o << "  endfacet\n";
				++ff;
			}			
			o << "endsolid ascii";
		// }
	}
	
} // end namespace
