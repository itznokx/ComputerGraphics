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
	// Base Center
	Vec3 cb;
	// Top-base center
	Vec3 ct;
	Vec4 colorAmb;
	Vec4 colorDif;
	Vec4 colorEsp;
	float m;
	CirclePlane bi,bs;
	bool cbActive,ctActive;
    Cilinder(Vec3 baseInferior,float _h,float _r,Vec3 _direction,Vec4 color,float _m,
    		bool _cbActive = true,bool _ctActive = true) 
    																						: 	h(_h),
			    																			radius(_r),
			    																			direction(_direction),
			    																			cb(baseInferior),
			    																			colorAmb(color),
			    																			colorDif(color),
			    																			colorEsp(color),
			    																			m(_m),
			    																			cbActive(_cbActive),
			    																			ctActive(_ctActive)
    {
    	Vec3 dc = normalize(_direction);
    	this->direction = dc;
    	this->ct = baseInferior+dc*_h;
    	this->bi = CirclePlane(baseInferior,-dc,_r);
    	this->bs = CirclePlane(baseInferior+dc*_h,dc,_r);
    }

    Cilinder(Vec3 baseInferior,Vec3 baseSuperior,float _r,Vec4 color,float _m,bool _cbActive = true,bool _ctActive = true) : 	
    																				radius(_r),
			    																	colorAmb(color),
			    																	colorDif(color),
			    																	colorEsp(color),
			    																	m(_m),
			    																	cbActive(_cbActive),
			    																	ctActive(_ctActive)
    {
    	Vec3 dc = baseSuperior-baseInferior;
    	this->h = dc.lenght();
    	this->direction = normalize(dc);
    }
    float intersects(Ray*);
    float intersectsCB(Ray*);
    float intersectsCT(Ray*);
    Vec4 returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs);
    bool validateIntersects(Ray*,float);

};
bool Cilinder::validateIntersects(Ray* ray,float ti){
	Vec3 pi = ray->at(ti*0.99);
	Vec3 vb = this->cb-pi;
	Vec3 va = this->ct-pi;
	float alfa = dot(vb,this->direction);
	float beta = dot(va,this->direction);
	if (alfa < 0 && beta < 0){
		return false;
	}
	else {
		if((alfa <= this->h)){
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}
float Cilinder::intersects (Ray* ray){
	Vec3 v = ray->origin - this->cb;
	Vec3 D_cross_A = cross(ray->dr,this->direction);
	Vec3 V_cross_A = cross(v,this->direction);
	float a = dot(D_cross_A);
    float b = 2.0 * dot(V_cross_A,D_cross_A);
    float c = dot(V_cross_A) - this->radius * this->radius;
	float delta = b*b - 4*a*c;
	float root =(delta<0)?-1:(-b-sqrt(delta))/(2.0f*a);
	if (validateIntersects(ray,root)){
		return root;
	}
	else {
		return -1;
	}
}
Vec4 Cilinder::returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs){
	//Vec4 finalColor = Vec4(1.0f,0.0f,0.0f,1.0f);
	// /*
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
		// */
		return finalColor;
}