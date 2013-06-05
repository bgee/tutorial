/**
 * @file ex2-includes.cpp
 * @author Can Erdogan
 * @date June 05, 2013
 * @brief This executable is a part of the tutorial for new students and it should be compiled with
 * the g++ compiler and include three headers. The headers are/should be located at: (1) in this 
 * folder, a subfolder and in /usr/include/eigen3. The last one is the location for the Eigen
 * library and if it is not there, use the 'locate' command to find out where it is.
 */

#include <iostream>
#include <Eigen/Dense>
#include "helper1.h"
#include "helper2.h"

using namespace Eigen;
using namespace std;

int main () {
	Vector2d temp (1.0, 2.0);
	cout << "Created a 2D vector: " << temp.transpose() << endl;
	cout << "The constant in helper1 is: " << helper1Const << endl;
	cout << "The function in helper2 returns: " << helper2Func() << endl;
}
