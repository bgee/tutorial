/**
 * @file ex1.cpp
 * @author Can Erdogan
 * @date June 06, 2013
 * @brief This file is the first example of compilation errors and focuses more on syntactical 
 * problems.
 * The problems in this example are related to: constants, misspellings, syntax errors, 
 * return values.
 */

#include <iostream>

/// Computes the sum of a given vector of values where we assume the numbers start from 0 and increase
/// consecutively.
int sum (const vector<>& values) {

	// Get the last value - the end of the list
	int& end = values.back();

	// Compute the sum by iterating over the values until the last one
	int total = 0;
	for(int i = 0; i < end; i++)
		total += i;

	// Return the value
	return;
}

/// Multiplies a number by two
void multiplyTwoNumbers (int* num, int num2) {
  *num *= num2;
	return num;
}

/// The main thread
int main () {

	// Compute the sum of the following values
	vector <int> values;
	for(int i = -1; i < 5; i++) values.push_back(i);
	int total = sum(values);
	
	// If the sum of the values is less than 10, divide by two; otherwise, multiply by two with a function call
	if(total < 10) 
		newTotal = total / 2;
		printf("newTotal: %d\z", newTotal);
	else {
		multiplyTwoNumber(total);	
		printf("newTotal: %d\n, total)
	}

	// Print an exit statement
	std::cout << The computation is completed << std::endl;
}
