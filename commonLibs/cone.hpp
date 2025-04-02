#include "vector.hpp"
#include "matrix.hpp"

class Cone : public Object{
public:
	float h;
	Vec3 base;
	Vec4 colorAmb;
	Vec4 colorDif;
	Vec4 colorEsp;
}