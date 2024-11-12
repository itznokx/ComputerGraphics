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
	void print (){
		printf("(%f,%f,%f)",this->x,this->y,this->z);
	}
};
class Vec4 {
	public:
	float x,y,z;
	float a;
	Vec4(float _x,float _y,float _z,float _a) : x(_x),y(_y),z(_z),a(_a)
	{}
	Vec4(Vec3* v,float _a) : x(v->x),y(v->y),z(v->z),a(_a)
	{}
	Vec4()
	{}
	void setX (float n){x=n;}
	void setY (float n){y=n;}
	void setZ (float n){z=n;}
	void setA (float n){a=n;}
	void print (){
		printf("(%f,%f,%f,%f)\n",this->x,this->y,this->z,this->a);
	}
};
//Header classes
float dot(Vec3*,Vec3*); //ok
float dot(Vec3 ,Vec3 ); //ok
Vec3 normalize(Vec3*); //ok
Vec3 normalize(Vec3 ); //ok
Vec3 operator+(Vec3,Vec3); // ok
Vec3 operator-(Vec3,Vec3);  // ok
Vec3 operator*(Vec3,float);  // ok
Vec3 operator*(float,Vec3);  // ok
Vec3 cross(Vec3,Vec3);
/*Vec4 operations*/

Vec4 operator*(Vec4,float); //ok
Vec4 operator+(Vec4,Vec4); //ok
float dot(Vec4,Vec4);
float dot(Vec4*,Vec4*);
Vec4 normalize(Vec4);
Vec4 normalize(Vec4*);
//operador arroba
Vec4 ats (Vec4,Vec4);
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
Vec3 operator*(float n,Vec3 v){
	return Vec3(v.x*n,v.y*n,v.z*n);
}
Vec3 operator*(Vec3 v,float n){
	return Vec3(v.x*n,v.y*n,v.z*n);
}
Vec3 operator-(Vec3 a,Vec3 b){
	return Vec3(a.x-b.x,a.y-b.y,a.z-b.z); 
}
Vec3 operator+(Vec3 a,Vec3 b){
	return Vec3(a.x+b.x,a.y+b.y,a.z+b.z);
}
Vec3 cross (Vec3 a,Vec3 b){
	float x = (a.y*b.z - a.z*b.y);
	float y = (a.z*b.x - a.x*b.z);
	float z = (a.x*b.y - a.y*b.x);
	return Vec3(x,y,z);
}
Vec4 ats(Vec4 a,Vec4 b){
	return Vec4(a.x*b.x,a.y*b.y,a.z*b.z,a.a*b.a);
}
Vec4 operator* (Vec4 v,float n){
	return Vec4(v.x*n,v.y*n,v.z*n,v.a*n);
}
Vec4 operator+ (Vec4 v,Vec4 w){
	return Vec4(v.x+w.x,v.y+w.y,v.z+w.z,v.a+w.a);
}
float dot (Vec4* v,Vec4* b){
	return (v->x*b->x+v->y*b->y+v->z*b->z+v->a*b->a);
}
float dot (Vec4 v,Vec4 b){
	return (v.x*b.x+v.y*b.y+v.z*b.z+v.a*b.a);
}
Vec4 normalize (Vec4 v) {
	float norm = sqrt(dot(v,v));
	return Vec4((v.x/norm),(v.y/norm),(v.z/norm),(v.a/norm)); 
}
Vec4 normalize (Vec4* v) {
	float norm = sqrt(dot(v,v));
	return Vec4((v->x/norm),(v->y/norm),(v->z/norm),(v->a/norm)); 
}