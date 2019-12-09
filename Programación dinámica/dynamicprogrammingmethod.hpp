#ifndef DYNAMICPROGRAMMINGMETHOD_HPP
#define DYNAMICPROGRAMMINGMETHOD_HPP

#include "algorithm.hpp"

class DynamicProgrammingMethod:public Algorithm
{
	private:
	public:
		DynamicProgrammingMethod(char * fileName, int numberPointsPolygonalApproximation);
		~DynamicProgrammingMethod();
		//Inherited method from algorithm class. It must be implemented in all inherited classes
		//This method calculates the polygonal approximation
		void apply();
		
};


#endif