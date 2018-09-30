

#ifndef __GEOMETRY_H_
#define __GEOMETRY_H_


class Ray;
class Vec3;
class Compute;
class color;


class Geometry
{
public:

	virtual ~Geometry(){}


	//return negative when the ray does not have intersection with the geometry
	virtual float getDistanceUntilHit(const Ray& ray) const = 0;

	//get normal vector from pos
	virtual const Vec3 getNormalForPos(const Vec3& pos) const = 0;
};



#endif //__GEOMETRY_H_




