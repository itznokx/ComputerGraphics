#include <iostream>
#include "../commonLibs/window.hpp"

int main (void){
	float rSphere = 5.0f;
	float dJanela = 5.0f;
	Sphere s1 = Sphere(Vec3(0,0,(dJanela+rSphere)),rSphere,Vec4(255,0,0,255));
	WindowSDL janela = WindowSDL(500,500);
	Vec4** matrix = colorMatrix(s1,5.0f,5.0f,
								500,500,dJanela);
	janela.renderScene(matrix);
	return 0;
}