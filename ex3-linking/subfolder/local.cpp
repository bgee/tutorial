/** 
 * @file local.cpp 
 * @author Can Erdogan
 * @date June 05, 2013
 * @brief This .cpp file is compiled into the libLocal.a library and contains a simple function
 * that returns a double.
 * Note a .cpp file can be turned into a library by first compiling it to an object file .o with
 * -c flag to g++ and then using the "ar -rc" command - look at man pages of ar / google it.
 */

/// Returns the PI value
double localLibFunc () {
	return 3.14;
}
