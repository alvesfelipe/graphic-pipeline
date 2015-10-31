#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <math.h>
#include "../pipeline/include/pipeline.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

typedef struct pixel {
	
	float x, y;
	int RGBA[4];

}Pixel;


void putLinha(int R, int G, int B, int A){

	for(int i=-1; i<2047; i+=4){

		FBptr[i+1] = R;
		FBptr[i+2] = G;
		FBptr[i+3] = B;
		FBptr[i+4] = A;
	}	
}

int posicaoPixel(int x, int y){

	int linha = ((y*4)*IMAGE_WIDTH);
	int coluna = (x*4);
	int posicao = linha + coluna;

	return posicao;
}

void putPixelOld(int x, int y, int R, int G, int B, int A){

	if((x>=0 && x<IMAGE_HEIGHT) && (y>=0 && y<IMAGE_WIDTH)){
		FBptr[posicaoPixel(x, y)+0] = R;
		FBptr[posicaoPixel(x, y)+1] = G;
		FBptr[posicaoPixel(x, y)+2] = B;
		FBptr[posicaoPixel(x, y)+3] = A;
	}	
}

void putPixel(Pixel p, Pixel cor){

	//teste para que não sejam plotados pixels indevidos na tela, limitando o desenho a apenas a area disponível
	if((p.x>=0 && p.x<IMAGE_HEIGHT) && (p.y>=0 && p.y<IMAGE_WIDTH)){
		FBptr[posicaoPixel(p.x, p.y)+0] = cor.RGBA[0];
		FBptr[posicaoPixel(p.x, p.y)+1] = cor.RGBA[1];
		FBptr[posicaoPixel(p.x, p.y)+2] = cor.RGBA[2];
		FBptr[posicaoPixel(p.x, p.y)+3] = cor.RGBA[3];
	}	
}

int delta(int x0, int x1){
	
	int delta = x1 - x0;
	
	return delta;
}

Pixel interpolColor(float p, Pixel color1, Pixel color2){
    
    Pixel color;
    
    color.RGBA[0] = color1.RGBA[0]*p + (1-p)*color2.RGBA[0];
    color.RGBA[1] = color1.RGBA[1]*p + (1-p)*color2.RGBA[1];
    color.RGBA[2] = color1.RGBA[2]*p + (1-p)*color2.RGBA[2];
    color.RGBA[3] = color1.RGBA[3]*p + (1-p)*color2.RGBA[3];
    
    return color;
}
//função para calcular a distancia entre dois pontos
float dist(Pixel pixel1, Pixel pixel2){
    //calculando a raiz quadrada    
    return sqrt((pixel2.x-pixel1.x)*(pixel2.x-pixel1.x)+(pixel2.y-pixel1.y)*(pixel2.y-pixel1.y));
} 


void drawLine(Pixel p0, Pixel p1){
	float distP;
    float distT = dist(p0,p1);	

	//variaveis auxiliares para alteração dos pixels
	Pixel aux0 = p0, aux1 = p1;
 	//calculo do delta x e delta y
    int deltaX = delta(aux0.x, aux1.x);    
    int deltaY = delta(aux0.y, aux1.y); 
    //armazenamento dos eixos
    int eixoMaior, eixoMenor;   
    int incrementoX0 = 0, incrementoY0 = 0, incrementoX1 = 0, incrementoY1 = 0, numerador;

    //testes para analisar se os eixos estão crescendo ou decrescendo de acordo com o delta
    if (deltaX > 0){            
    
        incrementoX0 = incrementoX1 = 1;
    }
    if (deltaX < 0){     
    
        incrementoX0 = incrementoX1 = -1;
    }
    if (deltaY > 0){            
    
        incrementoY0 = 1;
    }
    if (deltaY < 0){     
    
        incrementoY0 = -1 ;
    }
 
    if (abs(deltaX) >= abs(deltaY)){
     
        eixoMaior = abs(deltaX);
        eixoMenor = abs(deltaY);
    }else {
        
        eixoMaior = abs(deltaY);
        eixoMenor = abs(deltaX);
 
        if(deltaY > 0){         
        
            incrementoY1 = 1;
        }

        if (deltaY < 0){    
            incrementoY1 = -1;
 		}	
        
        incrementoX1 = 0;
    }
 
    numerador = eixoMaior/2;
 
    for (int i = 0; i <= eixoMaior; i++){
    	
    	distP = dist(aux0,aux1);
        Pixel color = interpolColor(distP/distT,p0,p1);	
        
        putPixel(aux0, color);
 
        numerador += eixoMenor;
 
        if (numerador > eixoMaior){
            
            numerador -= eixoMaior;
            aux0.x += incrementoX0;
            aux0.y += incrementoY0;
        }else {
            
            aux0.x += incrementoX1;
            aux0.y += incrementoY1;
        }
    }
	
}

void drawTriangle(Pixel p0, Pixel p1, Pixel p2){
	drawLine(p0,p1);
	drawLine(p1,p2);
	drawLine(p2,p0);
}

void printVectorPixel(std::vector<glm::vec4> v){
    Pixel p;
    int i = 0;

    while(i != v.size()){
        p.x = v[i][0];
        p.y = v[i][1];   
        p.RGBA[0] = 0;
        p.RGBA[1] = 255;
        p.RGBA[2] = 0;
        p.RGBA[3] = 255;
        
        putPixel(p, p);

        i++;
    }
}

void printTriangles(std::vector<glm::vec4> vertex, std::vector<glm::vec3> faces){
    Pixel p1, p2, p3;
    int i = 0;

    p1.RGBA[0] = 0; p1.RGBA[1] = 255; p1.RGBA[2] = 0; p1.RGBA[3] = 255;
    p2.RGBA[0] = 0; p2.RGBA[1] = 255; p2.RGBA[2] = 0; p2.RGBA[3] = 255;
    p3.RGBA[0] = 0; p3.RGBA[1] = 255; p3.RGBA[2] = 0; p3.RGBA[3] = 255;

    while(i != faces.size()){
        p1.x = vertex[faces[i][0]][0]; p1.y = vertex[faces[i][0]][1];   
        p2.x = vertex[faces[i][1]][0]; p2.y = vertex[faces[i][1]][1];
        p3.x = vertex[faces[i][2]][0]; p3.y = vertex[faces[i][2]][1];

        drawTriangle(p1, p2, p3);

        i++;
    }
}


#endif // _MYGL_H_

