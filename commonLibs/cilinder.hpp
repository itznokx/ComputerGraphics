#pragma once
#include "objects.hpp"
#include "matrix.hpp"
#include "circle.hpp"
using namespace std;
class Cilinder : public Object{
public:
	float h;
	float radius;
	Vec3 direction;
	Vec3 cb;
	Vec3 ct;
	Vec4 colorAmb;
	Vec4 colorDif;
	Vec4 colorEsp;
	float m;
	CirclePlane bi,bs;
    Cilinder(Vec3 baseInferior,float _h,float _r,Vec3 _direction,Vec4 color,float _m) : 	h(_h),
			    																			radius(_r),
			    																			cb(baseInferior),
			    																			direction(_direction),
			    																			colorAmb(color),
			    																			colorDif(color),
			    																			colorEsp(color),
			    																			m(_m)
    {
    	Vec3 dc = normalize(_direction);
    	this->bi = CirclePlane(baseInferior,-dc,_r);
    	this->ct = baseInferior+dc*_h;
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
    float intersects(Ray* ray);
    Vec4 returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs);

};
float Cilinder::intersects (Ray* ray){
	Vec3 oc = ray->origin - this->cb;
	float a = 1 - dot(ray->dr,this->direction)*dot(ray->dr,this->direction);
	float b = 2*(dot(oc,ray->dr))+ 2*(dot(oc,this->direction)*dot(ray->dr,this->direction));
	float c = dot(oc,oc) - (this->radius*this->radius) - (dot(oc,this->direction)*dot(oc,this->direction));
	float delta = b*b - 4*a*c;
	if (delta < 0)
		return -1.0f;
	else {
		// Check PI
		float ti =(-b - sqrt(delta) ) / (2.0f*a);
		Vec3 pI = ray->at(ti);
		Vec3 vCBP = pI - this->cb;
		float dotCheck = dot(pI,this->direction);
		if (dotCheck > 0 && dotCheck <= this->h){
			return ti;
		} 
		else{
			return -1;
		}
	}
}
Vec4 Cilinder::returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs){
	Vec3 pI = ray->at(ti);
		Vec4 iAmb = (ats(amb->intensity,this->colorAmb));
		for (Object *obj : objs){
			Ray* rayAux = new Ray(pI,lp->pF-pI);
			float tiAux = obj->intersects(rayAux);
			if(tiAux >= 0.0f && tiAux < 1.0f){
				return clamp(iAmb);
			}
		}
		Vec3 vCBP = (pI-this->cb);
		Vec3 vBP = vCBP - (dot(vCBP,this->direction)*this->direction); 
		Vec3 n = normalize(vBP);
		Vec3 l = normalize(lp->pF-pI);
		Vec3 v = normalize(ray->dr*(-1.0f));
		//Vec3 v = normalize(pI - ray->origin);
		Vec3 r = ((2.0f*(dot(l,n)*n))-l);
		float fd = dot(l,n);
		float fe = pow(dot(r,v),this->m);
		Vec4 iDif = (ats(lp->intensity,this->colorDif)*fd);
		Vec4 iEsp = (ats(lp->intensity,this->colorEsp)*fe);
		if (fd <= 0.0f && fe <= 0.0f)
			return iAmb;
		//cout << "fd: "<< fd << endl << "fe: "<< fe << endl;
		//cout << "iDif: "<< iDif << endl << "iEsp: "<< iEsp << endl;
		Vec4 finalColor;
		if (fd < 0.0f){
			finalColor = (iAmb+iEsp);
			finalColor = Vec4(	finalColor.x,
								finalColor.y,
								finalColor.z,
								1.0f
							);
			//cout << finalColor << endl;
			return finalColor;
		}
		if (fe < 0.0f){
			finalColor = (iAmb+iDif);
			finalColor = Vec4(	finalColor.x,
								finalColor.y,
								finalColor.z,
								1.0f
							);
			//cout << finalColor << endl;
			return finalColor;
		}
		finalColor = (iAmb+iDif+iEsp);
		finalColor = Vec4(	min(finalColor.x,1.0f),
							min(finalColor.y,1.0f),
							min(finalColor.z,1.0f),
							1.0f
						);
		return finalColor;
}