// Ray Sphere
#ifndef __RAYSPHERE_H__
#define __RAYSPHERE_H__

#include "geometry.h"
#include "../../maths/vec3.h"


class RaySphere : public Geometry
{
public:
	//construct function
	RaySphere(const Vec3& pos_, float radius_)
	{
		m_centerpos = pos_;
		m_radius = radius_;
		m_radiusSquared = radius_ * radius_;
		m_recipRadius = 1.0f / m_radius;
	}

	~RaySphere(){}

	// return the distance from starting point of ray to the sphere surface, if there's no intersection, return negative
	// If the ray comes from inside the sphere, no intersection
	virtual float getDistanceUntilHit(const Ray& ray) const;

	//normal vector of pos
	virtual const Vec3 getNormalForPos(const Vec3& pos) const;

	//center of sphere
	Vec3 m_centerpos;

private:

	float m_radius;//radius

	float m_radiusSquared;//square of radius

	float m_recipRadius;//reciprocal of the radius
};





#endif //__RAYSPHERE_H__