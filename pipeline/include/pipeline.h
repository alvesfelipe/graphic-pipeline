#ifndef PIPELINE_H
#define PIPELINE_H

#include "../libs/glm-0.9.7.1/glm/vec3.hpp" // glm::vec3
#include "../libs/glm-0.9.7.1/glm/vec4.hpp" // glm::vec4, glm::ivec4
#include "../libs/glm-0.9.7.1/glm/mat4x4.hpp" // glm::mat4
#include "../libs/glm-0.9.7.1/glm/gtc/matrix_transform.hpp" // glm::translate, glm::rotate, glm::scale, glm::perspective
#include "../libs/glm-0.9.7.1/glm/gtc/type_ptr.hpp" // glm::value_ptr
#include "../libs/glm-0.9.7.1/glm/glm.hpp"
#include "../libs/glm-0.9.7.1/glm/gtx/string_cast.hpp"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

class Pipeline{
	
	private:

	public:
		//model functions
		glm::mat4 modelMatrix();
		glm::mat4 translateMatrix(float x, float y, float z);
		glm::mat4 scaleMatrix(float x, float y, float z);
		glm::mat4 rotateX(float angle, float x);
		glm::mat4 rotateY(float angle, float y);	
		glm::mat4 rotateZ(float angle, float z);

		//view functions
		glm::vec3 normaCorrection(glm::vec3 vect);
		glm::mat4 viewMatrix(glm::vec3 position, glm::vec3 look, glm::vec3 up);

		//projection function
		glm::mat4 projectionMatrix(float d);

		//homogeneization
		glm::vec4 homogenVector(glm::vec4 vertex);

		//model view projection matrix
		glm::vec4 modelViewProjection(glm::vec3 position, glm::vec3 look, glm::vec3 up, float d, float x, float y, float z, float w);

		//print to screen
		glm::vec4 printScreen(glm::vec4 canonical, int width, int heigth);

		void test();
};

#endif