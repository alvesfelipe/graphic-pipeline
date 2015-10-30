#include "pipeline.h"
#include "main.h"

int main(int argc, char *argv[]){

	Pipeline* p =  new Pipeline();
	ifstream readSaida;
	string line;
	float x, y, z;

	//test();
	//cout << glm::to_string(cross(a,b)) << endl;
	//cout << glm::to_string(translateMatrix(2,2,2)) << endl;
	//cout << glm::to_string(Model[0]);
	//--------------------------------------TEST CUBE--------------------------------------------
	/*
	cout << "Model: " << glm::to_string(p->modelMatrix())<< endl;
	cout << "View: " << glm::to_string(p->viewMatrix(glm::vec3(0,0,5), glm::vec3(0,0,0), glm::vec3(0,1,0)))<< endl;
	cout << "Projection: " << glm::to_string(p->projectionMatrix(1)) << endl;
	glm::mat4 modelView = p->viewMatrix(glm::vec3(0,0,5), glm::vec3(0,0,0), glm::vec3(0,1,0)) * p->modelMatrix();
	cout << "Model View: " << glm::to_string(modelView) << endl;	
	cout << endl;
	glm::mat4 modelViewProjection =  modelView * p->projectionMatrix(1.0);
	cout << "Model View Projection: " << glm::to_string(modelViewProjection) << endl;	
	cout << endl;
	glm::vec4 transf = glm::vec4(-1,-1,1,1) * modelViewProjection; 
	cout << endl;
	glm::vec4 out = transf / transf[3];
	cout << glm::to_string(out)<< endl;
	*/
	readSaida.open(argv[1]);
	if(readSaida.is_open()){
		while(readSaida >>x>>y>>z)
			cout << glm::to_string(p->printScreen(p->modelViewProjection(glm::vec3(0,0,5), glm::vec3(0,0,0), glm::vec3(0,1,0), 1.0, x, y, z, 1), 512, 512)) << endl;		
	}
	readSaida.close();
	//cout << glm::to_string(homogenVector(transf)) << endl;

	return 0;
}