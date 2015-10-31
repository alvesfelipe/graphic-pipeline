#include "pipeline.h"
#include "../../cg_framework/main.h"

vector<glm::vec4> vectors;
vector<glm::vec3> faces;

void MyGlDraw(void){
	//printVectorPixel(vectors);
	printTriangles(vectors, faces);
}

int main(int argc, char *argv[]){

	Pipeline* p =  new Pipeline();
	Pixel pixel;
	
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();	
	
	p->printPixels(p->setVector(argv));
	faces = p->setFaces(argv);
	vectors = p->setVector(argv);

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}