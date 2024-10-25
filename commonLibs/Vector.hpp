#include <iostream>
#include <cmath>

using namespace std;
class Vec3 {
public:
	float x,y,z;
	Vec3(float _x,float _y,float _z) : x(_x),y(_y),z(_z)
	{}
	Vec3()
	{}
	void setX (float n){x=n;}
	void setY (float n){y=n;}
	void setZ (float n){z=n;}

};
class Vec4 {
	public:
	float x,y,z;
	int a;
	Vec4(float _x,float _y,float _z,int _a) : x(_x),y(_y),z(_z),a(_a)
	{}
	Vec4(Vec3* v,int _a) : x(v->x),y(v->y),z(v->z),a(_a)
	{}
	Vec4()
	{}
	void setX (float n){x=n;}
	void setY (float n){y=n;}
	void setZ (float n){z=n;}
	void setA (int n){a=n;}
};
