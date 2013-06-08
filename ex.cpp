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
  Sphere s1(1);
  Vec3f t1[3];
  t1[0].setValue(0, 0, 0);
  t1[1].setValue(1.5, 0, 0);
  t1[2].setValue(0, 1.5, 0);
	
	// Set the positions of the sphere so they barely miss (see test1.png)
	Transform3f trans (Vec3f(1.46, 1.46, 0.0));
  bool collision = solver.shapeTriangleIntersect(s1, trans, t1[0], t1[1], t1[2], NULL, NULL, NULL);
	EXPECT_FALSE(collision);

	// Now move the sphere a bit to the left/bottom and see if they collide
	Transform3f trans2 (Vec3f(1.45, 1.45, 0.0));
  collision = solver.shapeTriangleIntersect(s1, trans2, t1[0], t1[1], t1[2], NULL, NULL, NULL);
	EXPECT_TRUE(collision);

	// Move the sphere to the bottom of the triangle and collide with the corner
	Transform3f trans3 (Vec3f(-0.7, -0.7, 0.0));
  collision = solver.shapeTriangleIntersect(s1, trans3, t1[0], t1[1], t1[2], NULL, NULL, NULL);
	EXPECT_TRUE(collision);
}

/// The main thread runs the tests
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
