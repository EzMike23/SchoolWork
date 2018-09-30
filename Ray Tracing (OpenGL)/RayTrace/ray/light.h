//code for lighting
#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "color.h"
#include "../maths/vec3.h"



class Light
{
public:
	Light(const Vec3& pos_, const color& c)
	:	pos(pos_),
		color(c)
	{}

	~Light(){}

	//get the position of light
	inline const Vec3& getPos() const { return pos; }

	//get the color
	inline const color& getColour() const { return color; }

	Vec3 pos;
	color color;
};


#endif //__LIGHT_H__