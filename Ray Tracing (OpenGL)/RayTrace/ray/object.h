//code for object with material and geometry
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Material/material.h"
class Geometry;
class Vec3;
class Compute;


class Object
{
public:

	Object(const Material& material, Geometry* geometry);
	~Object();


	const Material& getMaterial() const { return m_material; }

	Geometry& getGeometry(){ return *m_geometry; }

private:
	Material m_material;//material
	Geometry* m_geometry;//geometry

};



#endif //__OBJECT_H__
