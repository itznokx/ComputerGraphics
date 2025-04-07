#include "vector.hpp"
#include "matrix.hpp"

class Cone : public Object{
public:
	Vec3 base;
	float h;
	float r; 
	Vec3 dr;
	Vec4 colorDif;
	Vec4 colorAmb;
	Vec4 colorEsp;
	Vec3 topPoint;
	Cone(Vec3 b,float height, float radius,Vec3 direction,Vec4 difcolor) :
	base(b),r(radius),dr(direction),
	colorDif(difcolor),colorAmb(difcolor),colorEsp(difcolor)
	{
		
		this->topPoint = b+(dr*height); 
	}
	Cone(Vec3 b,float height, float radius,Vec3 direction,Vec4 difcolor,
		Vec4 ambcolor, Vec4 espcolor) :
	base(b),r(radius),dr(direction),
	colorDif(difcolor),colorAmb(ambcolor),colorEsp(espcolor)
	{
		
		this->topPoint = b+(dr*height);
		this->colorAmb = difcolor;
		this->colorEsp = difcolor; 
	}
};