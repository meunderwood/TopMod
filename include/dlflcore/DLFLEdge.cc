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

/**
 * \file DLFLEdge.cc
 */

#include "DLFLEdge.hh"
#include "DLFLFaceVertex.hh"
#include "DLFLVertex.hh"

namespace DLFL {


  // Define the static variable. Initialized to 0

  NextOnFreeList *DLFLEdge::edge_pool = NULL;
  uint DLFLEdge::suLastID = 0;

  void DLFLEdge::dump(ostream& o) const
  {
    o << "DLFLEdge" << endl
      //    << "  ID : " << uID << endl
      << "  fvpV1 : " << fvpV1 << endl
      << "  fvpV2 : " << fvpV2 << endl
      //    << "  Type : " << etType << endl
      << endl;
  }

  // Update the mid point for this edge
  void DLFLEdge::updateMidPoint(void)
  {
    if ( fvpV1 != NULL && fvpV2 != NULL ) midpoint = 0.5 * (fvpV1->getVertexCoords() + fvpV2->getVertexCoords());
  }

  // Update the edge normal - average of normals at the 4 corners adjacent to this edge
  void DLFLEdge::updateNormal(void) {
    if ( fvpV1 != NULL && fvpV2 != NULL ) {
      normal = fvpV1->computeNormal() + fvpV1->next()->computeNormal() +
	fvpV2->computeNormal() + fvpV2->next()->computeNormal();
      normalize(normal);
    }
  }

  // Reverse the DLFL edge. Update face-vertex pointers appropriately
  // See comment in header file before using this function
  void DLFLEdge::reverse(void) // PRIVATE
  {
    // Clear edge pointer fields of original face-vertices
    // If edge is reversed then the next face-vertices will be the starting
    // points for this edge in the corresponding faces.
    // Update the edge pointer fields of the new face-vertices.
    //fvpV1->setEdgePtr(NULL);
    fvpV1 = fvpV1->next(); fvpV1->setEdgePtr(this);
    //fvpV2->setEdgePtr(NULL);
    fvpV2 = fvpV2->next(); fvpV2->setEdgePtr(this);
  }

  void DLFLEdge::updateFaceVertices(void)
  {
    fvpV1->setEdgePtr(this);
    fvpV2->setEdgePtr(this);
  }

  // Get face-vertex pointer belonging to give face. Returns NULL if not found
  DLFLFaceVertexPtr DLFLEdge::getFaceVertexPtr(DLFLFacePtr fptr)
  {
    DLFLFacePtr fp1, fp2;
    DLFLFaceVertexPtr fvp = NULL;
    fp1 = fvpV1->getFacePtr(); fp2 = fvpV2->getFacePtr();
    if ( fp1 == fptr ) fvp = fvpV1;
    else if ( fp2 == fptr ) fvp = fvpV2;
    return fvp;
  }

  // Check if two given edges are cofacial
  bool coFacial(DLFLEdgePtr ep1, DLFLEdgePtr ep2)
  {
    DLFLFacePtr fp11,fp12,fp21,fp22;
    ep1->getFacePointers(fp11,fp12);
    ep2->getFacePointers(fp21,fp22);
    bool cofacial = false;
    if ( fp11 == fp21 || fp11 == fp22 ||
	 fp12 == fp21 || fp12 == fp22 ) cofacial = true;
    return cofacial;
  }

  void DLFLEdge::getEndPoints(Vector3d& p1, Vector3d& p2) const
  {
    p1 = fvpV1->getVertexCoords(); p2 = fvpV2->getVertexCoords();
  }

  double DLFLEdge::length(void) const
  {
    return norm( fvpV1->getVertexCoords() - fvpV2->getVertexCoords() );
  }

  Vector3d DLFLEdge::getEdgeVector(void) const
  {
    return Vector3d( fvpV2->getVertexCoords() - fvpV1->getVertexCoords() );
  }

  void DLFLEdge::getFacePointers(DLFLFacePtr& fptr1, DLFLFacePtr& fptr2)
  {
    fptr1 = fvpV1->getFacePtr(); fptr2 = fvpV2->getFacePtr();
  }

  DLFLFacePtr DLFLEdge::getOtherFacePointer(DLFLFacePtr fptr)
  {
    // Each edge is adjacent to 2 faces (both can be same)
    // Return the pointer to the face which is not the given face pointer
    // NOTE: If both sides of the Edge are the same face, then
    // other face pointer will be the same.
    // If given face pointer is not adjacent to this edge, returns NULL
    if ( fvpV1->getFacePtr() == fptr ) return fvpV2->getFacePtr();
    else if ( fvpV2->getFacePtr() == fptr ) return fvpV1->getFacePtr();
    return NULL;
  }

  void DLFLEdge::getVertexPointers(DLFLVertexPtr& vp1, DLFLVertexPtr& vp2)
  {
    vp1 = fvpV1->getVertexPtr(); vp2 = fvpV2->getVertexPtr();
  }

  DLFLVertexPtr DLFLEdge::getOtherVertexPointer(DLFLVertexPtr vptr)
  {
    if ( fvpV1->getVertexPtr() == vptr ) return fvpV2->getVertexPtr();
    else if ( fvpV2->getVertexPtr() == vptr ) return fvpV1->getVertexPtr();
    return NULL;
  }

  void DLFLEdge::getEFCorners(DLFLFaceVertexPtrArray& corners)
  {
    corners.resize(4);
    corners[0] = fvpV1->next();
    corners[1] = fvpV1;
    corners[2] = fvpV2->next();
    corners[3] = fvpV2;
  }

  void DLFLEdge::getEFCornersAuxCoords(Vector3dArray& coords)
  {
    coords.resize(4);
    coords[0] = fvpV1->next()->getAuxCoords();
    coords[1] = fvpV1->getAuxCoords();
    coords[2] = fvpV2->next()->getAuxCoords();
    coords[3] = fvpV2->getAuxCoords();
  }

  // Equality operator - two edges are equal if they have the same 2 end-points
  bool operator == (const DLFLEdge& e1, const DLFLEdge& e2)
  {
    bool same = false;
    uint e11,e12,e21,e22;
  
    e11 = e1.fvpV1->getVertexID();
    e12 = e1.fvpV2->getVertexID();
    e21 = e2.fvpV1->getVertexID();
    e22 = e2.fvpV2->getVertexID();

    if ( (e11 == e21) && (e12 == e22) ) same = true;
    else if ( (e11 == e22) && (e12 == e21) ) same = true;
    return same;
  }

  bool DLFLEdge::isValid(void) const
  {
    if ( fvpV1->getFacePtr() == fvpV2->getFacePtr() ) return false;
    return true;
  }

  bool DLFLEdge::isSelfLoop(void) const
  {
    if ( fvpV1->getVertexPtr() == fvpV2->getVertexPtr() ) return true;
    return false;
  }

  bool checkIntersection(DLFLEdgePtr ep1, DLFLEdgePtr ep2) // friend function
  {
    // Check if the 2 given edges intersect
    // We will check only for in-plane intersections
    // So if the 4 end points do not lie on a plane, function will return false
    // If one end point of one edge lies on the other edge, it IS NOT considered an intersection
    // If the edges are co-linear, it IS NOT considered an intersection
    // If either of the edges are self loops, there is NO intersection
    if ( ep1->isSelfLoop() || ep2->isSelfLoop() )
      {
	cout << "Self loop" << endl;
	return false;
      }
    bool intersects = false;
    Vector3d ep1v1,ep1v2,ep2v1,ep2v2;
    ep1->getEndPoints(ep1v1,ep1v2);
    ep2->getEndPoints(ep2v1,ep2v2);

    // Find normals of triangle formed by ep1 and each end point of ep2
    // If angle between the normals is not 0 the 4 end points are not co-planar
    Vector3d n1 = (ep1v2-ep1v1) % (ep2v1-ep1v1); normalize(n1);
    Vector3d n2 = (ep1v2-ep1v1) % (ep2v2-ep1v1); normalize(n2);

    if ( normsqr(n1) < 1.0e-5 && normsqr(n2) < 1.0e-5 )
      {
	return false; // Co-linear edges
      }
  
    // Check the sum between n1 and n2
    // If difference is 0, the points are co-planar but ep2 lies
    // entirely on one side of ep1, so there is no possibility of intersection
    // If sum is 0, the points are co-planar and end points of ep2 lie
    // on either side of ep1. Then check if point of intersection is within the edge
    if ( normsqr(n1+n2) < 1.0e-4 )
      {
	// Points are co-planar, and there is possibility of intersection
	// Check if point of intersection is within the edge
	// We can simply check if ep1 is entirely on one side of ep2
	// If it is not, then there is an intersection
	n1 = (ep2v2-ep2v1) % (ep1v1-ep2v1); normalize(n1);
	n2 = (ep2v2-ep2v1) % (ep1v2-ep2v1); normalize(n2);
	if ( normsqr(n1+n2) < 1.0e-4 )
          {
            intersects = true;
          }
      }
    return intersects;
  }
       
  ostream& operator << (ostream& o, const DLFLEdge& e)
  {
    o << "Edge " << e.getID() << " : "
      << e.fvpV1->getVertexID() << "<-->"
      << e.fvpV2->getVertexID();
    return o;
  }

  void DLFLEdge::printFaceIDs(void) const
  {
    cout << "Edge " << uID << " : "
	 << fvpV1->getFaceID() << " (" << fvpV1->getVertexID() << ") " << "<--> "
	 << fvpV2->getFaceID() << " (" << fvpV2->getVertexID() << ") " << endl;
  }

  void DLFLEdge::printPointers(void) const
  {
    cout << fvpV1 << " <-> " << fvpV2;
  }

  // Write out the edge in DLFL format
  void DLFLEdge::writeDLFL(ostream& o) const
  {
    //o << "e {" << getID() << "} " << fvpV1->getIndex() << ' ' << fvpV2->getIndex() << endl;
    o << "e " << fvpV1->getIndex() << ' ' << fvpV2->getIndex() << endl;
  }

  // Write out the edge in DLFL format in reverse order
  // Reverse of edge will point to corners following the current corners
  void DLFLEdge::writeDLFLReverse(ostream& o) const
  {
    //o << "e {" << getID() << "} " << (fvpV1->next())->getIndex() << ' ' << (fvpV2->next())->getIndex() << endl;
    o << "e " << (fvpV1->next())->getIndex() << ' ' << (fvpV2->next())->getIndex() << endl;
  }

  // Distance of a point from the DLFLEdge in 3D
  double DLFLEdge::distFrom(double x, double y, double z) const
  {
    Vector3d p1,p2;                                      // 2 ends of the Edges
    Vector3d p(x,y,z);
  
    p1 = fvpV1->vertex->coords;
    p2 = fvpV2->vertex->coords;

    double len = norm(p1-p2);                            // Length of line segment
    double dist;
    if ( len < ZERO )
      {
	// Find distance from one of the 2 end points and return that
	dist = norm(p-p1);
      }
    else
      {
	double u;                                       // Parametric coordinate along edge
	// from p1 to p2
	u = ( (p-p1) * (p2-p1) ) / sqr(len);
	if ( u < 0.0 )
          {
            dist = norm(p-p1);
          }
	else if ( u > 1.0 )
          {
            dist = norm(p-p2);
          }
	else
          {
            Vector3d p3 = p1 + u * (p2-p1);
            dist = norm(p-p3);
          }
      }
    return dist;
  }

  // For hit calculations with projections
  double DLFLEdge::distFromXY(double x, double y) const
  {
    Vector3d p1temp,p2temp;
    Vector2d p1,p2;
    Vector2d p(x,y);
  
    p1temp = fvpV1->vertex->coords;
    p2temp = fvpV2->vertex->coords;

    // Convert to 2D coords in XY plane
    p1.set(p1temp[0],p1temp[1]); p2.set(p2temp[0],p2temp[1]);

    double len = norm(p1-p2);                            // Length of line segment in XY plane
    double dist;
    if ( len < ZERO )
      {
	// Find distance from one of the 2 end points and return that
	dist = norm(p-p1);
      }
    else
      {
	double u;                                       // Parametric coordinate along edge
	// from p1 to p2
	u = ( (p-p1) * (p2-p1) ) / sqr(len);
	if ( u < 0.0 )
          {
            dist = norm(p-p1);
          }
	else if ( u > 1.0 )
          {
            dist = norm(p-p2);
          }
	else
          {
            Vector2d p3 = p1 + u * (p2-p1);
            dist = norm(p-p3);
          }
      }
    return dist;
  }

  double DLFLEdge::distFromYZ(double y, double z) const
  {
    Vector3d p1temp,p2temp;
    Vector2d p1,p2;
    Vector2d p(y,z);
  
    p1temp = fvpV1->vertex->coords;
    p2temp = fvpV2->vertex->coords;

    // Convert to 2D coords in YZ plane
    p1.set(p1temp[1],p1temp[2]); p2.set(p2temp[1],p2temp[2]);

    double len = norm(p1-p2);                            // Length of line segment in YZ plane
    double dist;
    if ( len < ZERO )
      {
	// Find distance from one of the 2 end points and return that
	dist = norm(p-p1);
      }
    else
      {
	double u;                                       // Parametric coordinate along edge
	// from p1 to p2
	u = ( (p-p1) * (p2-p1) ) / sqr(len);
	if ( u < 0.0 )
          {
            dist = norm(p-p1);
          }
	else if ( u > 1.0 )
          {
            dist = norm(p-p2);
          }
	else
          {
            Vector2d p3 = p1 + u * (p2-p1);
            dist = norm(p-p3);
          }
      }
    return dist;
  }

  double DLFLEdge::distFromZX(double z, double x) const
  {
    Vector3d p1temp,p2temp;
    Vector2d p1,p2;
    Vector2d p(z,x);
  
    p1temp = fvpV1->vertex->coords;
    p2temp = fvpV2->vertex->coords;

    // Convert to 2D coords in ZX plane
    p1.set(p1temp[2],p1temp[0]); p2.set(p2temp[2],p2temp[0]);

    double len = norm(p1-p2);                            // Length of line segment in ZX plane
    double dist;
    if ( len < ZERO )
      {
	// Find distance from one of the 2 end points and return that
	dist = norm(p-p1);
      }
    else
      {
	double u;                                       // Parametric coordinate along edge
	// from p1 to p2
	u = ( (p-p1) * (p2-p1) ) / sqr(len);
	if ( u < 0.0 )
          {
            dist = norm(p-p1);
          }
	else if ( u > 1.0 )
          {
            dist = norm(p-p2);
          }
	else
          {
            Vector2d p3 = p1 + u * (p2-p1);
            dist = norm(p-p3);
          }
      }
    return dist;
  }

  // Distance betwen midpoint of two edges - friend function
  double distBetween(DLFLEdgePtr ep1, DLFLEdgePtr ep2)
  {
    return norm( ep1->getMidPoint() - ep2->getMidPoint() );
  }


  void resetEdgeType(DLFLEdgePtr dep) 
  {
    dep->resetType();
  }

  void makeEdgeUnique(DLFLEdgePtr dep) 
  {
    dep->makeUnique();
  }

  // Edge normal. See comments in header file for details
  /*Vector3d DLFLEdge::getEdgeNormal(DLFLFaceVertexPtr fvptr) const
    {
    Vector3d enormal;

    // Check if fvptr belongs to Edge
    if ( fvpV1 != fvptr && fvpV2 != fvptr ) return enormal;
  
    Vector3d normal = fvptr->computeNormal(); // Surface normal at corner
    Vector3d edge_vector = normalized(fvpV2->getVertexCoords() - fvpV1->getVertexCoords()); // Edge vector

    // Reverse edge vector if necessary
    if ( fvptr == fvpV2 ) edge_vector = -edge_vector;

    enormal = normal % edge_vector;

    return enormal;
    }

    Vector3d DLFLEdge::averageVertexNormal(void) const
    {
    Vector3d avn;

    avn = fvpV1->getVertexPtr()->averageNormal();
    avn += fvpV2->getVertexPtr()->averageNormal();

    normalize(avn);

    return avn;
    }*/

  /*Vector3d DLFLEdge::averageCornerNormal(void) const
    {
    Vector3d acn;

    acn = fvpV1->computeNormal() + fvpV2->computeNormal();
    normalize(acn);

    return acn;
    }*/
  /*
  // Render the DLFLEdge as a line segment
  void DLFLEdge::render(void) const
  {
  glBegin(GL_LINES);
  glVertex3dv((fvpV1->vertex->coords).getCArray());
  glVertex3dv((fvpV2->vertex->coords).getCArray());
  glEnd();
  }*/

} // end namespace
