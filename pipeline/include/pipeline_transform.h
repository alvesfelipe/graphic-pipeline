#ifndef _PIPELINE_TRANSFORM_H
#define _PIPELINE_TRANSFORM_H

#include <iostream>
#include <vector>
#include "../libs/boost_1_55_0/boost/numeric/ublas/matrix.hpp"
#include "../libs/boost_1_55_0/boost/numeric/ublas/io.hpp"

//using namespace boost::numeric::ublas;
using namespace std;

class PipelineTransform{

	private:

	public:
		vector<vector<float> > modelMatrix;
		void populateTest();
		void populateModel();
		
		//constructor
		PipelineTransform();
		//destructor
		~PipelineTransform();
};

#endif