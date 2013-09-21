/**
 * @file helper1.cpp
 * @author Can Erdogan
 * @date June 06, 2013
 * @brief Contains the class definition of A for examples 2.
 */

#include "helper1.h"

//A::A() : val1(1){}
int A::val1 = 1;
void A::incrementBsValue() {
  b->val += val1;
}

int A::getVal1 () const{ 
	return this->val1; 
}
	
int A::getVal2 () { 
	return val2; 
}	

B* A::getB () { 
	return this->b; 
}
