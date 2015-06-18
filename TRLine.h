/*
 * TRLine.h
 *
 *  Created on: Jun 18, 2015
 *      Author: sarahradzihovsky
 */

#include <complex>
#ifndef TRLINE_H_
#define TRLINE_H_
using namespace std;


class TRLine {
public:
	//TRLine(double zLoad, double Z0Coax, double betaCoax, double l);
	TRLine(double zLoad, CoaxXSection coaxXSect, double l);
	virtual ~TRLine();

	/* Function Prototypes */
		double getGamma();
		complex <double> getZin();

private:
	double zLoad, l;
	CoaxXSection coaxXSect;
};

#endif /* TRLINE_H_ */
