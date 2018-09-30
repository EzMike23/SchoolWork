// RayTrace.cpp : Defines the entry point for the console application.
//CS3388 ASN4
//Code by Yixin Zhang
//250817133
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include "ray/color.h"
#include "ray/Material/material.h"
#include "ray/Geometry/rayplane.h"
#include "ray/Geometry/raysphere.h"
#include "ray/object.h"
#include "ray/light.h"
#include "scene.h"
#include "GLUT.H"

#define WIDTH 600								
#define HEIGHT 600		

float lx=50;
float ly=100;

//scene
GLubyte showScene[HEIGHT][WIDTH][3];

Scene myscene(WIDTH,HEIGHT);

void CreatObj(){
	//insert object and light
	myscene.clear();
	myscene.setViewPostion(0,4,30);
	Object*sphere;
	Light*light;
	float planedist=-10;

	//ground
	{
		Material mat(color(0.7f,0.7f,0.7f),color(0.22f,0.25f,0.25f),color(0.45f,0.45f,0.45f),100.0f);
			
		RayPlane* plan = new RayPlane(Plane(Vec3(0,1,0), planedist));

		Object* ground = new Object(mat, plan);

		myscene.insertObject(ground);
	}
	
	//red ball
	{

		Material mat(color(0.0f,0.0f,0.0f),color(0.6f,0.0f,0.0f),color(0.6f,0.5,0.5f),100.0f);
			
		RaySphere* geom = new RaySphere(Vec3(10,planedist+12,-40),4);

		sphere = new Object(mat, geom);

		myscene.insertObject(sphere);
	}

	//grey ball
	{

		Material mat(color(0.0f,0.0f,0.0f),color(0.5f,0.5f,0.5f),color(0.5f,0.5f,0.5f),100.0f);

		RaySphere* geom = new RaySphere(Vec3(0,planedist+9,-35), 3);

		sphere = new Object(mat, geom);

		myscene.insertObject(sphere);
	}

	//blue ball
	{

		Material mat(color(0.0f,0.0f,0.0f),color(0.0f,0.0f,0.3f),color(0.7f,0.7f,0.7f),100.0f);

		RaySphere* geom = new RaySphere(Vec3(-7,planedist+14,-30), 4);

		sphere = new Object(mat, geom);

		myscene.insertObject(sphere);
	}
	//lighting
	light = new Light(Vec3(lx,ly,20), color(1, 1, 1) );
	myscene.insertLight(light);
	light = new Light(Vec3(0,3,20), color(0.4, 0.4, 0.4) );
	myscene.insertLight(light);

}


void myInit(){
	myscene.setTraceNum(1);
	CreatObj();
	myscene.draw();
}

//initialize
void initScene()
{
	int iHeight,iWidth;
	int iColorRed,iColorGreen,iColorBlue;
	for(iHeight=0;iHeight<HEIGHT;iHeight++){
		for(iWidth=0;iWidth<WIDTH;iWidth++){
			iColorRed=0;
			iColorGreen=0;
			iColorBlue=0;
			showScene[iHeight][iWidth][0]=(GLubyte)iColorRed;
			showScene[iHeight][iWidth][1]=(GLubyte)iColorGreen;
			showScene[iHeight][iWidth][2]=(GLubyte)iColorBlue;
		}
	}
}

//change the scene
void ResfreshScene()
{
	for(int i=0;i<HEIGHT;i++){
		for(int j=0;j<WIDTH;j++){
			showScene[i][j][0]=myscene.m_SceneImage[i][j][0];
			showScene[i][j][1]=myscene.m_SceneImage[i][j][1];
			showScene[i][j][2]=myscene.m_SceneImage[i][j][2];
		}
	}
}

//working with keyboards "w" "a" "s" "d"
void Keyboard(unsigned char key, int iXPos, int iYPos)
{
	if(key == 27) {
		exit(0);
	}else if(key=='a'){
		myscene.clearScene();
		lx-=20;
		CreatObj();
		myscene.draw();
		glutPostRedisplay();
	}
	else if(key=='d'){
		myscene.clearScene();
		lx+=20;
		CreatObj();
		myscene.draw();
		glutPostRedisplay();
	}else if(key=='w'){
		myscene.clearScene();
		ly-=20;
		CreatObj();
		myscene.draw();
		glutPostRedisplay();
	}
	else if(key=='s'){
		myscene.clearScene();
		ly+=20;
		CreatObj();
		myscene.draw();
		glutPostRedisplay();
	}
}
void Reshape(int w, int h)
{
	glutReshapeWindow(WIDTH,HEIGHT);
}


void Init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
	initScene();
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	CreatObj();
}


void Display() 
{	
	glClear(GL_COLOR_BUFFER_BIT);
	ResfreshScene();
	glDrawPixels(WIDTH,HEIGHT,GL_RGB,GL_UNSIGNED_BYTE,showScene);
	glutSwapBuffers();
}

int main(int argc,char** argv)
{
	myInit();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("RayTrace:control the lighting postion use W,A,S,D");
	Init();
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}

