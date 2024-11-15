#include <iostream>
#include "scene.hpp"
#include "color.hpp"
uint32_t* colorMatrix(Scene s1,float wJanela,float hJanela,int wCanvas,int hCanvas,float d){
	//Initialize color vector (alloc lines)
	uint32_t* final = new uint32_t[wCanvas*hCanvas];
	Vec3 observer = Vec3(0,0,0);
	float deltaX = wJanela/wCanvas;
	float deltaY = hJanela/hCanvas;
	float zP = -d;
	for (int lin=0;lin<hCanvas;lin++){
		float yP = (hJanela/2) - (deltaY/2) - (lin*deltaY);
		for (int col=0;col<wCanvas;col++){
			float xP = -(wJanela/2) + (deltaX/2) + (col*deltaX);
			Ray* auxRay = new Ray(observer,Vec3(xP,yP,zP)-observer);
			final[wCanvas*col+lin] = toRGBA(s1.returnColorScene(auxRay));
		}
	}
	return final;
}