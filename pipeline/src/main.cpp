#include "pipeline.h"
#include "../../cg_framework/main.h"
#include <unistd.h>

vector<glm::vec4> vectors;
vector<glm::vec4> originalVectors;
vector<glm::vec3> faces;

float angle = 0.0;	

void MyGlDraw(void){
	
	angle +=1.0;
	sleep(1);
	clearScreen();	
	rotateVector(originalVectors, faces, angle);
	//printTriangles(vectors, faces);	
	//printVectorPixel(vectors);
	
}

int main(int argc, char *argv[]){

	Pipeline* p =  new Pipeline();
	Pixel pixel;
	
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();	
	
	faces = p->setFaces(argv);
	vectors = p->setVector(argv);
	originalVectors = p->setOriginalVector(argv);
	//p->printPixels(originalVectors);
	
	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;
	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}