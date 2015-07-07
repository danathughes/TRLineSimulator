/*
 * CoaxXSection.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: sarahradzihovsky
 */

#include "CoaxXSection.h"
#include <iostream>
#include <math.h>
using namespace std;

/* Constants */
const double eps0 = 8.854 * pow(10.0 , -12.0);
const double mu0 = 4.0 * M_PI * pow(10.0, -7.0);

CoaxXSection::CoaxXSection(double r, double R, double eps)
{
	this -> r = r;
	this -> R = R;
	this -> eps = eps;
}

CoaxXSection::~CoaxXSection() {
}

double CoaxXSection::getZ0(){
	double F = getF();
	double eta = getEta();
	return F * eta;
}

double CoaxXSection::getF(){
	return ((1.0 / (2.0 * M_PI)) * log(R / r));
}

double CoaxXSection::getEta(){
	return sqrt(mu0 / (eps * eps0));
}

double CoaxXSection::getBeta(double f){
	return ((2.0 * M_PI) * f * sqrt(mu0 * eps * eps0));
}

