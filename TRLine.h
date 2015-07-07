/*
 * TRLine.h
 *
 *  Created on: Jun 18, 2015
 *      Author: sarahradzihovsky
 */

#include <complex>
#include "TRLineXSect.h"

#ifndef TRLINE_H_
#define TRLINE_H_
using namespace std;


class TRLine {
public:
	//TRLine(double zLoad, double Z0Coax, double betaCoax, double l);
        // DANA:  Altered this constructor to allow any type of 
	TRLine(complex<double> zLoad, TRLineXSect* trLineXSect, double l);
	virtual ~TRLine();

	/* Function Prototypes */
	complex <double> getGamma();
	complex <double> getZin(double f);
	complex <double> getZ0();
	double getBeta(double f);

private:
	complex<double> zLoad;
        double l;
	TRLineXSect* trXSect;
};

#endif /* TRLINE_H_ */
