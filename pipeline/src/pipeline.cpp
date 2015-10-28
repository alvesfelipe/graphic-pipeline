#include "../include/pipeline.h"

//----------------------------------MODEL MATRIX---------------------------------------------------
glm::mat4 Pipeline::modelMatrix(){
	glm::mat4 model = glm::mat4( 1.0 );

	return model;
}

glm::mat4 Pipeline::translateMatrix(float x, float y, float z){
	glm::mat4 translate(glm::vec4(1,0,0,x), glm::vec4(0,1,0,y), glm::vec4(0,0,1,z), glm::vec4(0,0,0,1));

	return translate;
}

glm::mat4 Pipeline::scaleMatrix(float x, float y, float z){
	glm::mat4 scale(glm::vec4(x,0,0,0), glm::vec4(0,y,0,0), glm::vec4(0,0,z,0), glm::vec4(0,0,0,1));

	return scale;
}

glm::mat4 Pipeline::rotateX(float angle, float x){
	glm::mat4 rotate(glm::vec4(1,0,0,0), glm::vec4(0,cos(angle),-sin(angle),0), glm::vec4(0,sin(angle),cos(angle),0), glm::vec4(0,0,0,1));

	return rotate;
}

glm::mat4 Pipeline::rotateY(float angle, float y){
	glm::mat4 rotate(glm::vec4(cos(angle),0,sin(angle),0), glm::vec4(0,1,0,0), glm::vec4(-sin(angle),0,cos(angle),0), glm::vec4(0,0,0,1));

	return rotate;
}

glm::mat4 Pipeline::rotateZ(float angle, float z){
	glm::mat4 rotate(glm::vec4(cos(angle),-sin(angle),0,0), glm::vec4(sin(angle),cos(angle),0,0), glm::vec4(0,0,1,0), glm::vec4(0,0,0,1));

	return rotate;
}
//-------------------------------------END MODEL--------------------------------------------------

//----------------------------------VIEW MATRIX---------------------------------------------------

glm::vec3 Pipeline::normaCorrection(glm::vec3 vect){

	for(int i=0; i<3; i++){
		if(glm::isnan(vect[i]) || glm::isinf(vect[i]))
			vect[i] = 0;
	}

	return vect;
}

glm::mat4 Pipeline::viewMatrix(glm::vec3 position, glm::vec3 look, glm::vec3 up){

	glm::mat4 view;

	glm::vec3 direction = look - position;
	glm::vec3 zCam = - (glm::normalize(direction));
	zCam = normaCorrection(zCam);
	//cout << "zcam: " << glm::to_string(zCam) << endl;
	glm::vec3 xCam = glm::cross(up, zCam) / glm::normalize(glm::cross(up, zCam));
	xCam = normaCorrection(xCam);
	//cout << "xcam: " << glm::to_string(xCam) << endl;
	glm::vec3 yCam = glm::cross(zCam, xCam) / glm::normalize(glm::cross(zCam, xCam));
	yCam = normaCorrection(yCam);
	//cout << "ycam: " << glm::to_string(yCam) << endl;
	glm::mat4 aux (glm::vec4(xCam[0], yCam[0], zCam[0], 0), glm::vec4(xCam[1], yCam[1], zCam[1], 0), glm::vec4(xCam[2], yCam[2], zCam[2], 0), glm::vec4(0,0,0,1));

	glm::vec3 auxT = position;

	glm::mat4 trans (glm::vec4(1,0,0,-(auxT[0])), glm::vec4(0,1,0,-(auxT[1])), glm::vec4(0,0,1,-(auxT[2])), glm::vec4(0,0,0,1));

	view = glm::transpose(aux) * trans;

	return view;
}

//-------------------------------------END VIEW--------------------------------------------------
	
//-------------------------------------PROJECTION MATRIX-----------------------------------------
glm::mat4 Pipeline::projectionMatrix(float d){

	glm::mat4 projection(glm::vec4(1,0,0,0), glm::vec4(0,1,0,0), glm::vec4(0,0,1,d), glm::vec4(0,0,-1/d,0));

	return projection;
}
//-------------------------------------END PROJECTION--------------------------------------------

//-------------------------------------HOMOGENEIZATION-------------------------------------------

glm::vec4 Pipeline::homogenVector(glm::vec4 vertex){

	vertex = vertex/vertex[4];

	return vertex;
}

//-------------------------------------END HOMOGENEIZATION-----------------------------------------

void Pipeline::test(){

    glm::vec4 Position = glm::vec4( glm::vec3( 0.0 ), 1.0 );

    modelMatrix()[3] = glm::vec4( 1.0, 1.0, 0.0, 1.0 );
    glm::vec4 Transformed = modelMatrix() * Position;
    
    std::cout << glm::to_string(modelMatrix()) << std::endl;
    std::cout << glm::to_string(Position) << std::endl;
    std::cout << glm::to_string(Transformed) << std::endl;
}

//-------------------------------------MODELVIEWPROJECTION-----------------------------------------
glm::vec4 Pipeline::modelViewProjection(glm::vec3 position, glm::vec3 look, glm::vec3 up, float d, float x, float y, float z, float w){

	glm::mat4 modelView = viewMatrix(position, look, up) * modelMatrix();
	glm::mat4 modelViewProjection =  modelView * projectionMatrix(d);
	glm::vec4 transf = glm::vec4(x, y, z, w) * modelViewProjection; 
	glm::vec4 out = transf / transf[3];

	return out;
}

//----------------------------------PRINTTOSCREEN---------------------------------------------------

glm::vec4 Pipeline::printScreen(glm::vec4 canonical, int width, int heigth){

	glm::mat4 intvertY( 1.0 );
	intvertY[1][1] = -1;

	glm::mat4 scale (glm::vec4(width/2, 0, 0, 0), glm::vec4(0, heigth/2, 0, 0), glm::vec4(0, 0, 1, 0), glm::vec4(0, 0, 0, 1));

	glm::mat4 translate (glm::vec4(1, 0, 0, (width-1)/2), glm::vec4(0, 1, 0, (heigth-1)/2), glm::vec4(0, 0, 1, 0), glm::vec4(0, 0, 0, 1));

	return canonical * intvertY * scale * translate;
}