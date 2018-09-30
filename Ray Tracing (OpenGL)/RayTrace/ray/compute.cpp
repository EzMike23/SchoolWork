#include"stdafx.h"

#include "Compute.h"


#include "object.h"
#include "color.h"
#include "ray.h"
#include "light.h"
#include "Geometry/geometry.h"
#include <assert.h>


const color ambient_lighting(0.3f, 0.3f, 0.3f);

Compute::Compute()
{
	m_traceNum=5;
}

Compute::~Compute()
{
	for(unsigned int i=0; i<m_objects.size(); ++i)
	{
		delete m_objects[i];
	}

	for(unsigned int z=0; z<m_lights.size(); ++z)
	{
		delete m_lights[z];
	}
}


void Compute::insertObject(Object* ob)
{
	m_objects.push_back(ob);
}



void Compute::insertLight(Light* light)
{
	m_lights.push_back(light);
}



//return the closest object that interests the ray, and then save the start point and end point into dist, if no interestions, return NULL, dist is negative
Object* Compute::closestObject(const Ray& ray,float& dist)
{
	Object* obj=NULL;
	float smallest_dist = 1e9f; 

	for(unsigned int i=0; i<m_objects.size(); i++)
	{
		const float tracedist = m_objects[i]->getGeometry().getDistanceUntilHit(ray);
	
		if(tracedist >= 0.0f && tracedist < smallest_dist)
		{
			smallest_dist = tracedist;
			obj = m_objects[i];
		}
	}
	if(obj==NULL)dist=-666;
	else dist=smallest_dist* 0.999f;
	return obj;
}

// get the color of ray, save it into colour_out
void Compute::getColourForRay(const Ray& ray, color& colour_out,int traceNum)
{


	if(traceNum<1){
		colour_out=color::black();
		return;
	}
	float dist;
	Object*obj=closestObject(ray,dist);
	if (!obj) 
	{
		colour_out=color::black();
		return;
	}
	//get the vector
	Vec3 V_in=ray.m_unitDir;
	Vec3 pos=ray.m_startPos+(ray.m_unitDir*dist);
	Vec3 N=obj->getGeometry().getNormalForPos(pos);
	N=normalise(N);
	Vec3 V_in_invers=V_in*(-1);
	V_in_invers=normalise(V_in_invers);
	Vec3 emergent_pos=(2*dot(N,V_in_invers))*N-V_in_invers;
	emergent_pos=normalise(emergent_pos);
	//get the data of the material
	color ka=obj->getMaterial().ka;
	color ks=obj->getMaterial().ks;
	color kd=obj->getMaterial().kd;
	float ns=obj->getMaterial().ns;
	//get the ambient lighting
	color I_ambient=ambient_lighting*ka;
	int num_light=m_lights.size();
	//get the diffusion
	color I_diffusion(0.0f,0.0f,0.0f);
	for(int i=0;i<num_light;i++)
	{
		Vec3 inc_antilight=m_lights[i]->getPos()-pos;
		inc_antilight=normalise(inc_antilight);
		Ray antilight(pos,inc_antilight);
		Vec3 juge=(m_lights[i]->getPos()-pos);
		float DIST;
		Object*jugeobject=closestObject(antilight,DIST);
		if((jugeobject==NULL||DIST>juge.length())&&dot(juge,N)>0) 
		{
			Vec3 h=inc_antilight+V_in_invers;
			h=normalise(h);
			I_diffusion+=m_lights[i]->getColour()*((kd*(dot(N,inc_antilight)))+ks*(pow(dot(N,h),ns)));
		}
	}
	static color I_reflexion(0.0f,0.0f,0.0f);
	static color I_reflexion_object(0.0f,0.0f,0.0f);
	Ray reflexion(pos,emergent_pos);
	getColourForRay(reflexion,I_reflexion_object,traceNum-1);
	I_reflexion=I_reflexion_object*ks;
	colour_out=I_ambient+I_diffusion+I_reflexion_object;
	



}

void Compute::setTraceNum(int traceNum)
{
	m_traceNum=traceNum;
}

void Compute::clear()
{
	int i=m_objects.size();
	for(int j=0;j<i;j++)
		delete m_objects[j];
	m_objects.clear();

	i=m_lights.size();
	for(int j=0;j<i;j++)
		delete m_lights[j];
	m_lights.clear();
}
