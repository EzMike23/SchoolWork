//header for Scene
#ifndef __SCENE_H__
#define __SCENE_H__

#include "ray/Compute.h"
#include "ray/ray.h"
#include "ray/color.h"
#include "ray/Material/material.h"
#include "ray/Geometry/rayplane.h"
#include "ray//Geometry/raysphere.h"
#include "ray/object.h"
#include "ray/light.h"


class Scene
{
public:
	
	Scene(int width,int height);
	
	~Scene(void);

	
	//set camera position
	void setViewPostion(float x,float y,float z){m_campos=Vec3(x,y,z);}

	//set trace number
	void setTraceNum(int traceNum){m_compute->setTraceNum(traceNum);}
	
	//insert object
	void insertObject(Object* ob);
	
	//insert light
	void insertLight(Light* light);
	
	//clear all
	void clear(){m_compute->clear();}

	
	//draw scene
	void draw();
	
	void clearScene();

	unsigned char***m_SceneImage;

private:

	//return the direction of ray that through the (x,y)
	Vec3 getUnitDirForImageCoords(int x, int y);

	//set the colour to the colour of pixel of (x,y)
	void drawPixel(int x,int y, color color);

	
	int mw,mh;//weight,height
	
	Compute*	m_compute;
	
	Vec3 m_campos;//camera position

};
#endif
