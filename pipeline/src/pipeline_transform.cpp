#include "pipeline_transform.h"



void PipelineTransform::populateTest(){
    
    boost::numeric::ublas::matrix<double> m(3, 3);

    for (unsigned i = 0; i < m.size1 (); ++ i){
        for (unsigned j = 0; j < m.size2 (); ++ j){
            m (i, j) = 3 * i + j;
    	}
    }

    //cout << m(0, 2) << std::endl;
}

void PipelineTransform::populateModel(){
	boost::numeric::ublas::matrix<int> C;
	boost::numeric::ublas::matrix<double> m(4, 4);
    boost::numeric::ublas::matrix<double> n(4, 4);

	for (unsigned i = 0; i < m.size1 (); ++ i){
        for (unsigned j = 0; j < m.size2 (); ++ j){
            m (i, j) = 4 * i + j;
            n (i, j) = 4 * i + j;
    	}
    }
    C = boost::numeric::ublas::trans(m);
    
    std::cout << m << std::endl;
    std::cout << n << std::endl;
    std::cout << C << std::endl;
}

//empty constructor
PipelineTransform::PipelineTransform(){}

//destructor
PipelineTransform::~PipelineTransform(){}

