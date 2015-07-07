/*
 * CoaxXSection.h
 *
 *  Created on: Jun 15, 2015
 *      Author: sarahradzihovsky
 */

#ifndef COAXXSECTION_H_
#define COAXXSECTION_H_

class CoaxXSection {
public:
	CoaxXSection(double r, double R, double eps);
	virtual ~CoaxXSection();

	/* Function Prototypes */

	double getZ0();
	double getF();
	double getEta();
	double getBeta(double f);

private:

	double r, R, eps;
};

#endif /* COAXXSECTION_H_ */
