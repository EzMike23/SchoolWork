//Create a ray plane
#ifndef __RAYPLANE_H__
#define __RAYPLANE_H__

#include "geometry.h"
#include "../../maths/plane.h"


class RayPlane : public Geometry
{
public:
	//contrust a function
	RayPlane(const Plane& plane);

	~RayPlane(){}


	//return negative if ray does not have intersection with plane
	//BUT! if ray comes through from the "back" of the plane, It means no intersection
	//if Plane "contains" this ray, it has no intersectons
	virtual float getDistanceUntilHit(const Ray& ray) const;

	//return normal vector
	virtual const Vec3 getNormalForPos(const Vec3& pos) const { 
		return m_plane.getNormal(); 
	}


private:
	//plane
	Plane m_plane;
};


#endif //__RAYPLANE_H__