#include "objects.hpp"
#include "plane.hpp"
#include "vector.hpp"

using namespace std;
class circlePlane : public Plane {
	Vec3 center;
}
class Cilinder : public Object{
	circlePlane bi,bs;
	float h;
	float r;
	Vec3 direction;
	Vec4 colorAmb;
	Vec4 colorDif;
	Vec4 colorEsp;
    Cilinder(Vec3 baseInferior,float _h,float _r,Vec3 _direction,Vec4 color) : 	h(_h),
    																			r(_r),
    																			direction(_direction),
    																			colorAmb(color),
    																			colorDif(color),
    																			colorEsp(color),  
    {
    	
    }
    Cilinder(Vec3 baseInferior,Vec3 baseSuperior,float r,Vec4 color)
}
