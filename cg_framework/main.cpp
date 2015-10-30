#include "main.h"

void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	//----------------------------------------------------------------------------------------
	//pixels default para teste
	Pixel p1, p2, p3;
	//setando pixel p1 VERMELHO
	p1.x = 50;
	p1.y = 450;
	p1.RGBA[0] = 255;
	p1.RGBA[1] = 0;
	p1.RGBA[2] = 0;
	p1.RGBA[3] = 255;
	//setando pixel p2 VERDE
	p2.x = 400;
	p2.y = 250;
	p2.RGBA[0] = 0;
	p2.RGBA[1] = 255;
	p2.RGBA[2] = 0;
	p2.RGBA[3] = 255;
	//setando pixel p3 AZUL
	p3.x = 350;
	p3.y = 450;
	p3.RGBA[0] = 0;
	p3.RGBA[1] = 0;
	p3.RGBA[2] = 255;
	p3.RGBA[3] = 255;
	//----------------------------------------------------------------------------------------
	//putLinha(255, 0, 0, 255);

	//pintar pixel vermelho
	//putPixel(p1);
	//pintar pixel verde
	//putPixel(p2);
	//pintar pixel azul
	//putPixel(p3);
	p1.x=0;
	p2.x=511;
	/*
	for (int i=0; i<512; i++){
		p1.y=i;
		p2.y=i;
		//drawLine(p1,p2);
	}
	
	//pintar diagonal 
	for(int i=0; i<512; i++){
		p2.x=i;
		p2.y=i;
		putPixel(p2, p2);
	}
	//pintar linha reta horizontal no meio 
	for(int i=0; i<512; i++){
		p3.x=i;
		p3.y=256;
		putPixel(p3, p3);
	}
	//pintar linha vertical
	for(int j=0; j<512; j++){
		p1.x=256;
		p1.y=j;
		putPixel(p1, p1);
	}
	//pintar diagonal inversa
	for(int i=0, j=512; i<512; i++, j--){
		p2.x=j;
		p2.y=i;
		putPixel(p2, p2);
	}
	*/
	//rasterizar linha 
	//drawLine(p1,p2);
	//rasterizar triangulo
	drawTriangle(p1,p2,p3);

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

