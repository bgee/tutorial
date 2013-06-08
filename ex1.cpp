/**
 * @file ex1.cpp
 * @author Can Erdogan
 * @date June 08, 2013
 * @brief This file is a part of the tutorial for new students and is written to demonstrate the 
 * importance of commenting. To do so, it carries out an algorithm, hopefully familiar to the
 * reader, in a very convoluted and uncommented way, and there is a slight problem with it
 * NOTE If you see a Nan or Inf in the results, re-run the program - just bad random values.
 */

#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int main () {

	double m [9], m2 [9];
	srand(time(NULL));
	while(true) {
		for(int i = 0; i < 9; i++) {
			m[i] = (rand() % 5)+1;
			m2[i] = (rand() % 5)+1;
		}
		double d = m[0] * (m[4] * m[8] - m[5] * m[7]) - m[1] * (m[3] * m[8] - m[5] * m[6]) + m[2] * (m[3] * m[7] - m[4] * m[6]);
		double d2 = m2[0] * (m2[4] * m2[8] - m2[5] * m2[7]) - m2[1] * (m2[3] * m2[8] - m2[5] * m2[6]) + m2[2] * (m2[3] * m2[7] - m2[4] * m2[6]);
		if((d != 0) && (d2 != 0)) break;
	}

	double p [9];
	p[0] = m[0] * m2[0] + m[1] * m2[3] + m[2] * m2[6]; 
	p[3] = m[3] * m2[0] + m[4] * m2[3] + m[5] * m2[6]; 
	p[6] = m[6] * m2[0] + m[7] * m2[3] + m[8] * m2[6]; 
	p[1] = m[0] * m2[1] + m[1] * m2[4] + m[2] * m2[7]; 
	p[4] = m[3] * m2[1] + m[4] * m2[4] + m[5] * m2[7]; 
	p[7] = m[6] * m2[1] + m[7] * m2[4] + m[8] * m2[7]; 
	p[2] = m[0] * m2[2] + m[1] * m2[5] + m[2] * m2[8]; 
	p[5] = m[3] * m2[2] + m[4] * m2[5] + m[5] * m2[8]; 
	p[8] = m[6] * m2[2] + m[7] * m2[5] + m[8] * m2[8]; 
	
	double e [] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	double* po = new double [9];
	memcpy(po, p, 9 * sizeof(double));
	double c1 = p[3] / p[0], c2 = p[6] / p[0];
	p[3] -= c1 * p[0], p[4] -= c1 * p[1], p[5] -= c1 * p[2];
	e[3] -= c1 * e[0], e[4] -= c1 * e[1], e[5] -= c1 * e[2];
	p[6] -= c2 * p[0], p[7] -= c2 * p[1], p[8] -= c2 * p[2];
	e[6] -= c2 * e[0], e[7] -= c2 * e[1], e[8] -= c2 * e[2];
  double c3 = p[7] / p[4];
	p[6] -= c3 * p[3], p[7] -= c3 * p[4], p[8] -= c3 * p[5];
	e[6] -= c3 * e[3], e[7] -= c3 * e[4], e[8] -= c3 * e[5];
	double c4 = p[5] / p[8];
	p[4] -= c4 * p[7], p[5] -= c4 * p[8];
	e[3] -= c4 * e[6], e[4] -= c4 * e[7], e[5] -= c4 * e[8];
	double c5 = p[2] / p[8];
	p[2] -= c5 * p[8];
	e[0] -= c5 * e[6], e[1] -= c5 * e[7],	e[2] -= c5 * e[8];
	double c6 = p[1] / p[4];
	p[1] -= c6 * p[4];
	e[0] -= c6 * e[3], e[1] -= c6 * e[4],	e[2] -= c6 * e[5];
	e[0] /= p[0], e[1] /= p[0], e[2] /= p[0];
	e[3] /= p[4], e[4] /= p[4], e[5] /= p[4];
	e[6] /= p[8], e[7] /= p[8], e[8] /= p[8];
	memcpy(p, po, 9 * sizeof(double));

	// I think I switched two of the variable names below. Otherwise, I should not get
	// any assertion errors.

	double t [9];
	t[0] = e[0] * m2[0] + e[1] * m2[3] + e[2] * m2[6]; 
	t[3] = e[3] * m2[0] + e[4] * m2[3] + e[5] * m2[6]; 
	t[6] = e[6] * m2[0] + e[7] * m2[3] + e[8] * m2[6]; 
	t[1] = e[0] * m2[1] + e[1] * m2[4] + e[2] * m2[7]; 
	t[4] = e[3] * m2[1] + e[4] * m2[4] + e[5] * m2[7]; 
	t[7] = e[6] * m2[1] + e[7] * m2[4] + e[8] * m2[7]; 
	t[2] = e[0] * m2[2] + e[1] * m2[5] + e[2] * m2[8]; 
	t[5] = e[3] * m2[2] + e[4] * m2[5] + e[5] * m2[8]; 
	t[8] = e[6] * m2[2] + e[7] * m2[5] + e[8] * m2[8]; 

	double r [9];
	r[0] = m[0] * t[0] + m[1] * t[3] + m[2] * t[6]; 
	r[3] = m[3] * t[0] + m[4] * t[3] + m[5] * t[6]; 
	r[6] = m[6] * t[0] + m[7] * t[3] + m[8] * t[6]; 
	r[1] = m[0] * t[1] + m[1] * t[4] + m[2] * t[7]; 
	r[4] = m[3] * t[1] + m[4] * t[4] + m[5] * t[7]; 
	r[7] = m[6] * t[1] + m[7] * t[4] + m[8] * t[7]; 
	r[2] = m[0] * t[2] + m[1] * t[5] + m[2] * t[8]; 
	r[5] = m[3] * t[2] + m[4] * t[5] + m[5] * t[8]; 
	r[8] = m[6] * t[2] + m[7] * t[5] + m[8] * t[8]; 

	for(size_t i = 0; i < 9; i++) {
		if(i % 4 == 0) assert(fabs(r[i] - 1) < 1e-5);
		else assert(fabs(r[i]) < 1e-5);
	}
}
