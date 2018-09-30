//Materials
#ifndef __MATERIAL_H_
#define __MATERIAL_H_


#include "../color.h"
#include <stdio.h>


class Material
{
public:

	Material(const color ambient=color(0.2f,0.2f,0.2f),const color diffuse=color(0.8f,0.8f,0.8f),const color specular=color(0.0f,0.0f,0.0f),float specularFactor=5.0f);

	Material(const Material& m):ka(m.ka),kd(m.kd),ks(m.ks),ns(m.ns){
		
	}

	inline Material& operator=(const Material m){
		ka=m.ka;
		kd=m.kd;
		ks=m.ks;
		ns=m.ns;
		
	}

	~Material(){}

	color 
		ka,kd,ks;
	float ns;

};


#endif //__MATERIAL_H_




