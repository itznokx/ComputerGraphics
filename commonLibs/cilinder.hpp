#pragma once
#include "objects.hpp"
#include "matrix.hpp"
#include "circle.hpp"
using namespace std;
class Cilinder{
	float h;
	float radius;
	Vec3 direction;
	Vec4 colorAmb;
	Vec4 colorDif;
	Vec4 colorEsp;
	float m;
	CirclePlane bi,bs;
    Cilinder(Vec3 baseInferior,float _h,float _r,Vec3 _direction,Vec4 color,float _m) : 	h(_h),
			    																			radius(_r),
			    																			direction(_direction),
			    																			colorAmb(color),
			    																			colorDif(color),
			    																			colorEsp(color),
			    																			m(_m)
    {
    	Vec3 dc = normalize(_direction);
    	this->bi = CirclePlane(baseInferior,-dc,_r);
    	this->bs = CirclePlane(baseInferior+dc*_h,dc,_r);
    }

    Cilinder(Vec3 baseInferior,Vec3 baseSuperior,float _r,Vec4 color,float _m) : 	radius(_r),
			    																	colorAmb(color),
			    																	colorDif(color),
			    																	colorEsp(color),
			    																	m(_m)
    {
    	Vec3 dc = baseSuperior-baseInferior;
    	this->h = dc.lenght();
    	this->direction = normalize(dc);
    }
};
