/**
 * @file ex3-linking.cpp
 * @author Can Erdogan
 * @date June 05, 2013
 * @brief This executable is a part of the tutorial for new students and it should be compiled with
 * the g++ compiler and link to two libraries. The first library is FCL which will be used in
 * motion planning and it is located/should be located in /usr/local/lib. Its headers are in
 * /usr/local/include/fcl. The second library is in a subfolder and the declaration of its function
 * will not be in a header file but in this file instead. As long as the declaration of a variable/
 * function is before its use, it does not matter where it is.  
 */

#include <iostream>

#include "fcl/narrowphase/narrowphase.h"
#include "fcl/collision.h"

using namespace std;
using namespace fcl;

/// The declaration of the local library's function that returns pi
double localLibFunc();

/// The declaration of the local library's function that returns euler's number
double localLibFunc2();

/// The main thread
int main () {

	// Create a sphere with radius (?) 10.0 units
	Sphere s1 (10.0);
	cout << "Created a sphere with fcl library" << endl;
	
	// Make calls from the local library
	double value = localLibFunc();
	double value2 = localLibFunc2();
	cout << "Local lib functions return: " << value << " and " << value2 << endl;	
}
