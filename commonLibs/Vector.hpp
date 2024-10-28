#pragma once
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
//Header classes
float dot(Vec3*,Vec3*); //ok
float dot(Vec3 ,Vec3 ); //ok
Vec3 normalize(Vec3*); //ok
Vec3 normalize(Vec3 ); //ok
Vec3 operator+(Vec3,Vec3); // ok
Vec3 operator-(Vec3,Vec3);  // ok
Vec3 operator*(Vec3,float);  // ok
Vec3 operator*(Vec3,Vec3);  // ok
// Implementation 
float dot (Vec3* a,Vec3* b){
	return (a->x*b->x+a->y*b->y+a->z*b->z);
}
float dot (Vec3 a,Vec3 b){
	return (a.x*b.x+a.y*b.y+a.z*b.z);
}
Vec3 normalize (Vec3* a) {
	float norm = sqrt(dot(a,a));
	return Vec3((a->x/norm),(a->y/norm),(a->z/norm)); 
}
Vec3 normalize (Vec3 a) {
	float norm = sqrt(dot(a,a));
	return Vec3((a.x/norm),(a.y/norm),(a.z/norm)); 
}
Vec3 operator*(Vec3 a,Vec3 b){
	return Vec3(a.x*b.x,a.y*b.y,a.z*b.z);
}
Vec3 operator*(Vec3 a,float b){
	return Vec3(a.x*b,a.y*b,a.z*b);	
}
Vec3 operator-(Vec3 a,Vec3 b){
	return Vec3(a.x-b.x,a.y-b.y,a.z-b.z); 
}
Vec3 operator+(Vec3 a,Vec3 b){
	return Vec3(a.x+b.x,a.y+b.y,a.z+b.z);
}
