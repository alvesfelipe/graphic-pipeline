#include "pipeline_transform.h"

int main(){
	
	PipelineTransform *pTransform = new PipelineTransform();

	//test matrix 3x3
	pTransform->populateTest();

	//matrix model
	pTransform->populateModel();

	return 0;
}