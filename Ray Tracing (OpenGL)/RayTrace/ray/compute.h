//Code for computing ray tracing
#ifndef _COMPUTE_H_
#define _COMPUTE_H_

#include <vector>
#include "../maths/vec3.h"

class Vec3;
class Object;
class Light;
class Ray;
class color;

class Compute
{
public:
	Compute();
	~Compute();

	//get the color of the ray
	//If the start poing is camera, then the colour is "colour_out"
	void getColourForRay(const Ray& ray, color& colour_out,int traceNum);
	

	//insert an object
	void insertObject(Object* ob);

	//insert a light
	void insertLight(Light* light);

	//get the number of traces
	int getTraceNum(){return m_traceNum;}

	//set the trace number
	void setTraceNum(int traceNum);

	//clear all
	void clear();


private:

	//return the closest object that interests the ray, and then save the start point and end point into dist, if no interestions, return NULL, dist is negative
	Object* closestObject(const Ray& ray,float& dist);

	std::vector<Object*> m_objects;//object

	std::vector<Light*> m_lights;//light 

	int m_traceNum;//trace number
};


#endif //_COMPUTE_H_