/*
 * MicrostripXSection.h
 *
 *  Created on: Jun 15, 2015
 *      Author: sarahradzihovsky
 */

#ifndef MICROSTRIPXSECTION_H_
#define MICROSTRIPXSECTION_H_
#include <iostream>
#include <math.h>
using namespace std;

class MicrostripXSection {
public:
	MicrostripXSection(double w, double h, double t, double eps);
	~MicrostripXSection();

	/* Function Prototypes */

	double getZ0();
	double getF();
	double getEta();
	double getBeta(double f);

private:

	double w, h, t, eps;

};

#endif /* MICROSTRIPXSECTION_H_ */
