/**
 * @file helper1.cpp
 * @author Can Erdogan
 * @date June 06, 2013
 * @brief Contains the class definition of A for examples 2.
 */

#include "helper1.h"

void A::incrementBsValue() {
	B->val += val1;
}

int getVal1 () { 
	return val1; 
}
	
int B::getVal2 () { 
	return val2; 
}	

B* getB () { 
	return b; 
}
