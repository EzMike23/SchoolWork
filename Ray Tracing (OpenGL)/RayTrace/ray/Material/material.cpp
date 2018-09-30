#include"stdafx.h"

#include "material.h"

#include <assert.h>
#include <stdio.h>

Material::Material(const color ambient,const color diffuse,const color specular,float specularFactor)
{
	ka=ambient;
	kd=diffuse;
	ks=specular;
	ns=specularFactor;

}