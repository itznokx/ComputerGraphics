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
	for (int lin=0;lin<hCanvas;++lin){
		for (int col=0;col<wCanvas;++col){
			float xP = (-wJanela/2.0f) + (deltaX/2.0f) + (col*deltaX);
			float yP = (hJanela/2.0f) - (deltaY/2.0f) - (lin*deltaY);
			Ray* auxRay = new Ray(observer,Vec3(xP,yP,zP));
			//cout << auxRay->dr << endl;
			int index = (wCanvas*lin)+col;
			Vec4 color = s1.returnColorScene(auxRay);
			final[index] = toRGBA(color);
		}
	} 
	return final;
}