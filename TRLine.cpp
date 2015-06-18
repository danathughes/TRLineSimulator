/*
 * TRLine.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: sarahradzihovsky
 */

#include "TRLine.h"
#include <iostream>
#include <math.h>
#include <complex>

using namespace std;

//typedef complex<double> num;
//typedef complex<double> denom;

//TRLine::TRLine(double zLoad, double Z0Coax, double betaCoax, double l) {
//	this -> zLoad = zLoad;
//	this -> Z0 = Z0Coax;
//	this -> beta = betaCoax;
//	this -> l = l;
//}

TRLine::TRLine(double zLoad, CoaxXSection coaxXSect, double l) {
	this -> zLoad = zLoad;
	this -> coaxXSect = coaxXSect;
	this -> l = l;
}

TRLine::~TRLine() {
}

double TRLine::getGamma(){
	return (zLoad - coaxXsect.getZ0()) / (zLoad + coaxXsect.getZ0());
}

complex <double> TRLine::getZin(){
	double i;
	i = -1;
	i = sqrt(i);
	complex <double> num = zLoad + 1i * (coaxXsect.getZ0() * tan(coaxXsect.getBeta() * l));
	complex <double> denom = coaxXsect.getZ0() + 1i * (zLoad * tan(coaxXsect.getBeta() * l));
	return coaxXsect.getZ0() * (num / denom);
}
