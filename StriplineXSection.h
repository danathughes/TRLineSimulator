/*
 * StriplineXSection.h
 *
 *  Created on: Jun 15, 2015
 *      Author: sarahradzihovsky
 */

#ifndef STRIPLINEXSECTION_H_
#define STRIPLINEXSECTION_H_

class StriplineXSection {
public:
	StriplineXSection(double w, double b, double t, double eps);
	~StriplineXSection();

	/* Function Prototypes */

	double getZ0();
	double getF();
	double getEta();
	double getBeta(double f);
	int main();

private:

	double w, b, t, eps;
};

#endif /* STRIPLINEXSECTION_H_ */
