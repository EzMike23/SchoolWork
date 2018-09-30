//code for ray
#ifndef __RAY_H_666_
#define __RAY_H_666_



#include "../maths/vec3.h"


class Ray
{
public:
	Ray(const Vec3& m_startPos_, const Vec3& unitdir_)
	:	m_startPos(m_startPos_),
		m_unitDir(unitdir_)
	{}

	~Ray(){}

	Vec3 m_startPos;//start point
	Vec3 m_unitDir;//unit direction vector
};


#endif //__RAY_H_666_