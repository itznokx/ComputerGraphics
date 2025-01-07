#pragma once
#include <iostream>
#include <cmath>
using namespace std;

#define tMax 9999.9f
#define Vec40 Vec4(0.0f,0.0f,0.0f,0.0f)
#define Vec41 Vec4(1.0f,1.0f,1.0f,1.0f)
#define coefError 0.99998f
#define coefErrorPlane 0.0099f
class Vec3 {
public:
	float x,y,z;
	Vec3(float pX,float pY,float pZ) : x(pX),y(pY),z(pZ)
	{}
	Vec3()
	{}
	void setX (float n){x=n;}
	void setY (float n){y=n;}
	void setZ (float n){z=n;}
	void print (){
		printf("(%f,%f,%f)\n",this->x,this->y,this->z);
	}
	float lenght() const {
		return sqrt(lenght_squared());
	}
	float lenght_squared() const {
		return (x*x+y*y+z*z);
	}
	Vec3 operator-() const{
		return Vec3((-1.0f)*this->x,(-1.0f)*this->y,(-1.0f)*this->z);
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
	float lenght_squared() const {
		return (x*x+y*y+z*z+a*a);
	}
	float lenght() const {
		return sqrt(lenght_squared());
	}
};
//Vec3 operations declaration
float dot(Vec3 ,Vec3 ); //ok
Vec3 normalize(Vec3*); //ok
Vec3 normalize(Vec3 ); //ok
Vec3 operator+(Vec3,Vec3); // ok
Vec3 operator-(Vec3,float); 
Vec3 operator-(Vec3,Vec3);  // ok
Vec3 operator*(Vec3,float);  // ok
Vec3 operator*(float,Vec3);  // ok
Vec3 cross(Vec3,Vec3);
/*Vec4 operations declaration*/
Vec4 operator*(Vec4,float); //ok
Vec4 operator+(Vec4,Vec4); //ok
float dot(Vec4,Vec4);
float dot(Vec4*,Vec4*);
Vec4 normalize(Vec4);
Vec4 normalize(Vec4*);
Vec4 operator*(Vec4 ,Vec3 );
Vec4 operator*(Vec3 ,Vec4 );
Vec4 operator*(Vec4 ,Vec4 );
inline std::ostream& operator<<(ostream&,Vec4);
Vec4 ats (Vec4,Vec4);
Vec4 clamp(Vec4,Vec4,Vec4);
Vec4 operator/(Vec4,float n);
Vec4 toAbs(Vec4);
Vec4 cross(Vec4,Vec4);
// Vec3 Implementation 
float dot (Vec3 a,Vec3 b){
	return (a.x*b.x+a.y*b.y+a.z*b.z);
}
float dot (Vec3 v){
	return dot(v,v);
}
Vec3 normalize (Vec3* a) {
	float norm = a->lenght();
	return Vec3((a->x/norm),(a->y/norm),(a->z/norm)); 
}
Vec3 normalize (Vec3 a) {
	float norm = a.lenght();
	return Vec3((a.x/norm),(a.y/norm),(a.z/norm)); 
}
Vec3 operator*(Vec3 a,Vec3 b){
	return Vec3(a.x*b.x,a.y*b.y,a.z*b.z);
}
Vec3 operator*(Vec3 v,float n){
	return Vec3(v.x*n,v.y*n,v.z*n);
}
Vec3 operator*(float n,Vec3 v){
	return v*n;
}
Vec3 operator-(Vec3 a,Vec3 b){
	return Vec3(a.x-b.x,a.y-b.y,a.z-b.z); 
}
Vec3 operator-(Vec3 v,float n){
	return Vec3(v.x-n,v.y-n,v.z-n);
}
Vec3 operator+(Vec3 a,Vec3 b){
	return Vec3(a.x+b.x,a.y+b.y,a.z+b.z);
}
Vec3 operator/(Vec3 v,float n){
	return v*(1/n);
}
Vec3 cross (Vec3 a,Vec3 b){
	float x = (a.y*b.z - a.z*b.y);
	float y = (a.z*b.x - a.x*b.z);
	float z = (a.x*b.y - a.y*b.x);
	return Vec3(x,y,z);
}
inline std::ostream& operator<<(ostream& out,Vec3 v){
	return out << "(" << v.x << " , " << v.y << " , " << v.z << ")";
}
// Vec4 Implementations
Vec4 ats(Vec4 a,Vec4 b){
	return Vec4(a.x*b.x,a.y*b.y,a.z*b.z,a.a*b.a);
}
Vec4 operator* (Vec4 v,float n){
	return Vec4(v.x*n,v.y*n,v.z*n,v.a*n);
}
Vec4 operator* (float n,Vec4 v){
	return v*n;
}
Vec4 operator+ (Vec4 v,Vec4 w){
	return Vec4(v.x+w.x,v.y+w.y,v.z+w.z,v.a+w.a);
}
Vec4 operator+ (Vec4 v,float n){
	return Vec4(v.x+n,v.y+n,v.z+n,v.a+n);
}
float dot (Vec4* v,Vec4* b){
	return (v->x*b->x+v->y*b->y+v->z*b->z+v->a*b->a);
}
float dot (Vec4 v,Vec4 b){
	return (v.x*b.x+v.y*b.y+v.z*b.z+v.a*b.a);
}
Vec4 normalize (Vec4 v) {
	float norm = v.lenght();
	return Vec4((v.x/norm),(v.y/norm),(v.z/norm),(v.a/norm)); 
}
Vec4 normalize (Vec4* v) {
	float norm = v->lenght();
	return Vec4((v->x/norm),(v->y/norm),(v->z/norm),(v->a/norm)); 
}
Vec4 operator*(Vec4 v,Vec3 b){
	return Vec4 (v.x*b.x,v.y*b.y,v.z*b.z,v.a);
}
Vec4 operator*(Vec3 b,Vec4 v){
	return v*b;
}
Vec4 operator*(Vec4 v1,Vec4 v2){
	return Vec4(v1.x*v2.x,v1.y*v2.y,v1.z*v2.z,v1.a*v2.a);
}
inline std::ostream& operator<<(ostream& out,Vec4 v){
	return out << "(" << v.x << " , " << v.y << " , " << v.z << " , " << v.a << ")";
}
Vec4 clamp(Vec4 u,Vec4 v,Vec4 t) {
	float x = std::min(std::max(u.x, v.x), t.x);
	float y = std::min(std::max(u.y, v.y), t.y);
	float z = std::min(std::max(u.z, v.z), t.z);
	float a = std::min(std::max(u.a, v.a), t.a);
	return Vec4(x, y, z, a);
}
Vec4 clamp(Vec4 u) {
	float x = std::min(std::max(u.x, 0.0f), 1.0f);
	float y = std::min(std::max(u.y, 0.0f), 1.0f);
	float z = std::min(std::max(u.z, 0.0f), 1.0f);
	float a = std::min(std::max(u.a, 0.0f), 1.0f);
	return Vec4(x, y, z, a);
}
Vec4 operator/(Vec4 v,float t){
	return v*(1/t);
}
Vec4 toAbs(Vec4 v){
	return Vec4(abs(v.x),
				abs(v.y),
				abs(v.z),
				1.0f);
}