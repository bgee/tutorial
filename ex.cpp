/**
 * @file ex.cpp
 * @author Can Erdogan
 * @date June 07, 2013
 * @brief This file shows an example usage of a testing library, GTest, to ensure that a
 * collision library, FCL, performs as expected.
 */

#include <gtest/gtest.h>
#include "fcl/narrowphase/narrowphase.h"
#include "fcl/collision.h"
#include "fcl/math/transform.h"
#include "fcl/collision_data.h"
#include "fcl/collision_object.h"
#include <iostream>

using namespace std;
using namespace fcl;

/// The collision detector
GJKSolver_libccd solver;

/// Testing triangle sphere collisions at different configurations.
TEST(EXAMPLE, TriangleSphere) {

	// Create the sphere with radius 10 and equilateral triangle with 20 side length
  Sphere s1(10);
  Vec3f t1[3];
  t1[0].setValue(20, 0, 0);
  t1[1].setValue(-20, 0, 0);
  t1[2].setValue(0, 20, 0);
	
	// Set the positions of the sphere and radius so they intersect
	Transform3f trans (Vec3f(100.0, 0.0, 0.0));
  bool res = solver.shapeTriangleIntersect(s1, trans, t1[0], t1[1], t1[2], NULL, NULL, NULL);
	cout << "result: " << res << endl;
	
}

/// The main thread runs the tests
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
