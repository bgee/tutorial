/**
 * @file helper1.h
 * @author Can Erdogan
 * @date June 06, 2013
 * @brief Contains the class definition of A for examples 2.
 * What is the difference between a static and normal field member? Google!
 * How do you declare a static variable in a class?
 * NOTE: Do not change the public/private definitions of members. That is usually a simple
 * solution/hack but would defeat the purpose of the exercise.
 */

// #include "helper2.h"

/// Forward declare class B
class B;

/// The definition of class A
class A {

	B* b;																	///< The B instance
	static int val1 = 1;									///< The fixed value 
	int val2;															///< The input value

public:

	/// The constructor with a parameter
	A (int input) : val2(input) {
	}

	// Add a const here
	void incrementBsValue (); 						///< Increment Bs value

	// The getter function that returns private variables
	int getVal1 const ();												///< Returns val2
	int getVal2 ();												///< Returns val2
	B* getB () { return b; }							///< Returns the local instance of B
};
