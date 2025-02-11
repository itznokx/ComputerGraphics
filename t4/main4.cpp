 #include "../commonLibs/window.hpp"
#include "../commonLibs/scene.hpp"
#include <cmath>
int main (void){
	float rSphere = 40.0f;
	float dJanela = 10.0f;
	float cilinderX = float(-1/sqrt(3));
	Scene cena;
	Light l1 = Light(Vec3(0.0f,40.0f,-20.0f),Vec4(0.7f, 0.7f, 0.7f,1.0f));
	cena.insertLight(&l1);
	Sphere s1 = Sphere(Vec3(-30.0f,0.0f,-100.0f),rSphere,Vec4(0.7f, 0.2f, 0.2f,1.0f),9.0f);
	Sphere s2 = Sphere(Vec3(30.0f,0.0f,-100.0f),rSphere,Vec4(0.7f, 0.0f, 0.7f,1.0f),9.0f);
	Cilinder c1 = Cilinder (Vec3(0.0f,0.0f,-40.0f),
							rSphere,
							rSphere/3,
							Vec3(0.0f,1.0f,0.0f),
							Vec4 (0.2f,0.3f,0.8f,1.0f),
							1.0f)
							;

	Plane p1 = Plane(Vec3(0.0f,-rSphere,0.0f),
					 Vec3(0.0f,1.0f,0.0f),
					 Vec4(0.7f,0.7f,0.2f,1.0f),1.0f);
	Plane p2 = Plane(Vec3(0.0f,0.0f,-200.0f),
					 Vec3(0.0f,0.0f,1.0f),
					 Vec4(0.3f,0.3f,0.7f,1.0f),1.0f);
	cena.setAmbientLight(Vec4(0.3f, 0.3f, 0.3f,1.0f));
	cena.insertObj(&s1);
	cena.insertObj(&s2);
	cena.insertObj(&c1);
	cena.insertObj(&p1);
	cena.insertObj(&p2);
	Matrix3 aux;
	aux.makeIdentity();
	aux.print();
	WindowSDL janela = WindowSDL(500,500);
	uint32_t* matrix = colorMatrix(cena,60.0f,60.0f,
								500,500,dJanela);
	janela.renderScene(matrix);
	return 0;
}
