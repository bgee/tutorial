/**
 * @file helper1.cpp
 * @author Can Erdogan
 * @date June 06, 2013
 * @brief Contains the class definition of A for examples 2.
 */

#include "helper1.h"

// @edit
static int val1 = 1;


void A::incrementBsValue() {
	b->val += val1;
}

int getVal1 () { 
	return val1; 
}
	
int A::getVal2 () { 
	return val2; 
}	
// @edit
// remove the conflicting function
/*
B* getB () { 
	return b; 
}
*/
