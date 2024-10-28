#include <iostream>
#include "objects.hpp"
Vec4** colorMatrix (Sphere sphere,float wJanela,float hJanela,int wCanvas,int hCanvas,float d){
	//Initialize color vector (alloc lines)
	Vec4** matrixFinal = new Vec4*[hCanvas];
	// aloc collumns
	for (int i=0;i<=wCanvas;i++){
		matrixFinal[i] = new Vec4[wCanvas];
	}

	float deltaX = wJanela/wCanvas;
	float deltaY = hJanela/hCanvas;
	float zP = -d;
	for (int lin=0;lin<=hCanvas-1;lin++){
		float yP = (hJanela/2) - (deltaY/2) - (lin*deltaY);
		for (int col=0;col<=wCanvas-1;col++){
			float xP = -(wJanela/2) + (deltaX/2) + (col*deltaX);
			float deltaInter = sphere.intersects(new Ray(Vec3(0,0,0),Vec3(xP,yP,zP)));
			if (deltaInter >= 0){
				matrixFinal[lin][col] = Vec4(255,0,0,255);
			}
			else {
				matrixFinal[lin][col] = Vec4(100,100,100,255);
			}

		}
	}
	return matrixFinal;
}