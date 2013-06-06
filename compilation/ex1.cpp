/**
 * @file ex1.cpp
 * @author Can Erdogan
 * @date June 06, 2013
 * @brief This file is the first example of compilation errors and focuses more on syntactical 
 * problems.
 */

/// Computes the sum of a given vector of values where we assume the numbers start from 0 and increase
/// consecutively.
int sum (const vector<int>& values) {

	// Get the last value - the end of the list
	int& end = values.back();

	// Compute the sum by iterating over the values until the last one
	int sum = 0;
	for(int i = 0; i < end; i++)
		sum += i;
}

int main () {

	// Compute the sum of the following values
	vector <int> values;
	for(size_t i = -1; i < 5; i++) values.push_back(i);
	

	// 
	

}
