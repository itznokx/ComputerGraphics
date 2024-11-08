#include <iostream>
#include <algorithm>
#include "ray.hpp"
#include "light.hpp"
using namespace std; 

class Object {
public:
	Vec4 color;
	string type;
	void setColor(int r,int g,int b,int a){
		this->color = Vec4(r,g,b,a);
	}
	virtual float intersects(Ray* ray);
};
float Object::intersects(Ray* ray){
	return -404.404f;
}
//Sphere
class Sphere : public Object{
public:
	Vec4 color;
	string type;
	Vec3 center;
	float r;
	Sphere(Vec3 _center,float _r,Vec4 _color) : color(_color),type("Sphere"),center(_center), r(_r)  
	{}
	float intersects(Ray* ray){
		Vec3 v = ray->Origin - this->center;
		float a = dot(ray->dr,ray->dr);
		float b = 2.0f*(dot(v,ray->dr));
		float c = (dot(v,v)) - pow(this->r,2);
		float delta = b*b - 4.0f*a*c;

		if (delta < 0){
				return -1.0f;
		}
		else{
			float t2 = -1*(-b-sqrt(delta))/(2.0f*a);
			cout << t2 << " ";
			return t2;
			/*else {
				float t1= (-b+sqrt(delta))/(2*a);
				if ((t1>=0)&&(t2>=0)){
					return min(t1,t2); 
				}
				else{
					return max(t1,t2);
				}
			}*/

		}
	}
};
class Plane : public Object{
	Vec3 anchorPoint;
	Vec3 normal;
	Vec4 color;
	string type;
	Plane (Vec3 nP,Vec3 _normal,Vec4 _color):anchorPoint(nP),normal(_normal),color(_color),type("Plane"){}
	Plane (Vec3 p1,Vec3 p2,Vec3 p3,Vec4 _color):color(_color),type("Plane"){
		Vec3 w = cross((p2-p1),(p3-p1));
		this->normal = normalize(w); 
	}
	float intersects(Ray* ray){
		return -1.0f;
	}
};