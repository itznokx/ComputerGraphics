#include "objects.hpp"
#include "matrix.hpp"
using namespace std;
class CirclePlane{
	Vec3 center;
	Vec3 normal;
	float radius;
	Vec4 colorAmb;
	Vec4 colorDif;
	Vec4 colorEsp;
	float m;
	CirclePlane(Vec3 _center,Vec3 direction,float _radius) : 	center(_center), 
																normal(direction), 
																radius(_radius)
	{}
};

class Cilinder : public Object{
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
    	bi = CirclePlane(baseInferior,(-1.0f*normalize(_direction)),_r);
    	bs = CirclePlane(baseInferior+_direction*_h,normalize(direction),_r)
    }

    Cilinder(Vec3 baseInferior,Vec3 baseSuperior,float _r,Vec4 color,float _m) : 	radius(_r),
			    																	colorAmb(color),
			    																	colorDif(color),
			    																	colorEsp(color),
			    																	m(_m)
    {
    	direction = baseSuperior-baseInferior;
    	float h = direction.lenght();
    	direction = normalize(direction);
    }
};
