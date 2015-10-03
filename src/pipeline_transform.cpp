#include "pipeline_transform.h"

void PipelineTransform::populateTest(){
    
    matrix<double> m(3, 3);

    for (unsigned i = 0; i < m.size1 (); ++ i){
        for (unsigned j = 0; j < m.size2 (); ++ j){
            m (i, j) = 3 * i + j;
    	}
    }

    //cout << m(0, 2) << std::endl;
}

void PipelineTransform::graphPipeline(){
	
	matrix<double> m(4, 4);

	for (unsigned i = 0; i < m.size1 (); ++ i){
        for (unsigned j = 0; j < m.size2 (); ++ j){
            m (i, j) = 4 * i + j;
    	}
    }

    cout << m << endl;
}

//empty constructor
PipelineTransform::PipelineTransform(){}

//destructor
PipelineTransform::~PipelineTransform(){}

