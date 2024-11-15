#include <iostream>
#include "../commonLibs/window.hpp"
#include "../commonLibs/scene.hpp"

using namespace std;

int main (void){
	float rSphere = 5.0f;
	float dJanela = 5.0f;
	Scene cena;
	Sphere s1 = Sphere(Vec3(0.f,0.f,-10.0f),rSphere,Vec4(0.7f, 0.2f, 0.2f,1.0f),1.0f);
	Sphere s2 = Sphere(Vec3(0.0f,5.0f,-10.0f),rSphere,Vec4(0.2f, 0.2f, 0.7f,1.0f),10.0f);
	Plane p1 = Plane(Vec3(0.0f,0.0f,-200.0f),
					 Vec3(0.0f,1.0f,0.0f),
					 Vec4(0.2f,0.7f,0.7f,1.0f),1.0f);
	Light l1 = Light(Vec3(0.0f,5.0f,0.0f),Vec4(0.7f, 0.7f, 0.7f,1.0f));
	cena.insertLight(&l1);
	cena.setAmbientLight(Vec4(0.f, 0.f, 0.f,1.0f));
	std::cout << "Sphere created\n";
	cena.insertObj(&s1);
	//cena.insertObj(&p1);
	// cena.insertObj(&s2);
	WindowSDL janela = WindowSDL(500,500);
	Vec4** matrix = colorMatrix(cena,10.0f,10.0f,
								500,500,dJanela);
	std::cout << "Matrix of color created\n";
	janela.renderScene(matrix);
	std::cout << "Scene rendered\n";
	return 0;
}