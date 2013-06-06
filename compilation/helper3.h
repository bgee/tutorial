/**
 * @file helper3.h
 * @author Can Erdogan
 * @date June 06, 2013
 * @brief Contains the class definition of A for examples 3.
 */

/// Template class definition
/// The type of the member of the class, value, will be decided upon the creation
template <class T>
class C {
public:

	T value;			///< The local variable

	/// The constructor
	C(T input) : value(input) {};

};
