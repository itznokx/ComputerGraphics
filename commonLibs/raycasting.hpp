#include <iostream>
#include "scene.hpp"
Vec4** colorMatrix (Scene s1,float wJanela,float hJanela,int wCanvas,int hCanvas,float d){
	//Initialize color vector (alloc lines)
	Vec4** matrixFinal = new Vec4*[hCanvas];
	// aloc collumns
	for (int i=0;i<=wCanvas;i++){
		matrixFinal[i] = new Vec4[wCanvas];
	}
	Vec3 observer = Vec3(0,0,0);
	float deltaX = wJanela/wCanvas;
	float deltaY = hJanela/hCanvas;
	float zP = -d;
	for (int lin=0;lin<hCanvas;lin++){
		float yP = (hJanela/2) - (deltaY/2) - (lin*deltaY);
		for (int col=0;col<wCanvas;col++){
			float xP = -(wJanela/2) + (deltaX/2) + (col*deltaX);
			Ray* auxRay = new Ray(observer,Vec3(xP,yP,zP)-observer);
			matrixFinal[lin][col] = s1.returnColorScene(auxRay);
		}
	}
	return matrixFinal;
}