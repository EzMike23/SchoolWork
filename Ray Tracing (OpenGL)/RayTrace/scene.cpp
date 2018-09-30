//Code by Yixin Zhang, 250817133
#include"stdafx.h"
#include "scene.h"
#include <stdlib.h>
#include <math.h>

Scene::Scene(int width,int height):mw(width),mh(height)
{
	m_compute=new Compute();
	m_campos=Vec3(0,5,2);
	m_SceneImage=(unsigned char***)malloc(height*sizeof(unsigned char**));
	for(int i=0;i<height;i++){
		m_SceneImage[i]=(unsigned char**)malloc(width*sizeof(unsigned char*));
		for(int j=0;j<width;j++)
			m_SceneImage[i][j]=(unsigned char*)malloc(3*sizeof(unsigned char));
	}
}

Scene::~Scene(void)
{
	clearScene();
}
void Scene::insertObject(Object* ob){
	m_compute->insertObject(ob);
}
void Scene::insertLight(Light* light){
	m_compute->insertLight(light);
}
void Scene::draw()
{

	//set the scene
	for(int x=0; x<mw; ++x)
		for(int y=0; y<mh; ++y)
		{
			//tracing the ray from comera position
			const Ray ray(m_campos, getUnitDirForImageCoords(x, y));

			color color;
			m_compute->getColourForRay(ray, color,m_compute->getTraceNum());

			color.positiveClipComponents();

			//set pixel
			drawPixel(x, y, color);
		}
}
void Scene::clearScene()
{

	m_compute->clear();
}
Vec3 Scene::getUnitDirForImageCoords(int x, int y)
{
	if(x>=0&&x<mw&&y>=0&&y<mh){
		float vx=-10+20*((float)x)/mw-m_campos.x;
		float vy=-10+20*((float)y)/mh-m_campos.y;
		float vz=-m_campos.z;
		return normalise(Vec3(vx,vy,vz));
	}
	else return Vec3(0,0,-1);
}
void Scene::drawPixel(int x,int y, color color)
{
	m_SceneImage[y][x][0]= unsigned char(color.r * 255);
	m_SceneImage[y][x][1]= unsigned char(color.g * 255);
	m_SceneImage[y][x][2]= unsigned char(color.b * 255);
}
