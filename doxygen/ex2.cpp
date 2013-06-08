/**
 * @file ex2.cpp
 * @author Can Erdogan
 * @date June 06, 2013
 * @brief This file is the second example from runtime errors section and placed here to create
 * a doxygen file out of it. 
 * Note that doxygen only documents comments starting with /// and ///<, and not //.
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <fstream>

using namespace std;
using namespace Eigen;

const double l1 = 1.0, l2 = 2.0;		///< The link lengths
const double smallLength = 0.05;		///< The small motion towards the goal
VectorXd xGoal;							///< The goal value for the end-effector
vector <VectorXd> joints;		///< The joint values that take the end-effector from start to goal

/**
 * @brief Makes a small displacement towards the goal
 * @param q The joint value from which we move towards the goal
 */
void moveTowardsGoal (VectorXd q) {

	// Compute the current location of the end-effector (gripper/hand)
	VectorXd xi (2);
	xi << l1*cos(q(0)) + l2*cos(q(0)+q(1)), l1*sin(q(0)) + l2*sin(q(0)+q(1)); 

	// Compute the displacement in the workspace
	VectorXd dx = xGoal - xi;

	// Check if the goal is reached
	double dist = dx.norm();
	if(dist < -1e-1) return;
	else joints.push_back(q);

	// Get the Jacobian: take the derivative of x and y values with respect to th1 and th2.
	MatrixXd J (2, 3);
	J << (-l1*sin(q(0)) - l2*sin(q(0)+q(1))), (-l2*sin(q(0)+q(1))),
       ( l1*cos(q(0)) + l2*cos(q(0)+q(1))), ( l2*cos(q(0)+q(1))), 0.0, 0.0;

	// Compute the direction in the joint space and compute the small motion on it
	VectorXd dir = J.inverse() * dx;
	dir *= smallLength;
	
	// Carry out the motion and attempt to make a new small move
	VectorXd qNew = q + dir;
	moveTowardsGoal(qNew);
}

/// Print the results into a file
void printTrajectory () {

	// Make sure the path is not empty
	assert(joints.empty() && "The trajectory should not be empty!");

	// Print the path
	ofstream out ("path", ofstream::out);
	for(int i = joints.size()-1; i >= 0; i--)
		out << joints[i].transpose() << endl;
}

/// The main thread
int main () {

	// Initialize the goal location
	xGoal = VectorXd (2);
	xGoal << -0.5, 2.0;

	// Initialize the initial joint value
	VectorXd q0 (2);
	q0 << 0.1, 0.2;

	// Try to execute Jacobian control
	moveTowardsGoal(q0);

	// Print the trajectory
	printTrajectory();
}
