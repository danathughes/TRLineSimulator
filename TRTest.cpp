/*
 * TRTest.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: sarahradzihovsky
 */

#include "CoaxXSection.h"
#include "StriplineXSection.h"
#include "MicrostripXSection.h"
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	/*for microstrip*/
	double w, h, t, eps, f;
	cout << "Width (m):"<< endl;
	cin >> w;
	cout << "Height (m):"<< endl;
	cin >> h;
	cout << "Thinkness of Inner Strip (m):"<< endl;
	cin >> t;
	cout << "Permittivity:"<< endl;
	cin >> eps;
	cout << "Frequency (Hz):"<< endl;
	cin >> f;
	MicrostripXSection microXSect(w, h, t, eps);

	cout << "Z0, Beta = "  << microXSect.getZ0() << ", "
			<< microXSect.getBeta(f) << endl;

	/*for stripline*/
	double b;
	//double w, b, t, eps, f;
	cout << "Width (m):"<< endl;
	cin >> w;
	cout << "Height (m):"<< endl;
	cin >> b;
	cout << "Thinkness of Inner Strip (m):"<< endl;
	cin >> t;
	cout << "Permittivity:"<< endl;
	cin >> eps;
	cout << "Frequency (Hz):"<< endl;
	cin >> f;

	StriplineXSection stripXSect(w, b, t, eps);

	cout << "Z0, Beta = " << stripXSect.getZ0() << " ohm, "
			<< stripXSect.getBeta(f) << " rad/m" << endl;

	/* for coax*/
	double r, R;
	cout << "Small Radius (m):"<< endl;
	cin >> r;
	cout << "Large Radius (m):"<< endl;
	cin >> R;
	cout << "Permittivity:"<< endl;
	cin >> eps;
	cout << "Frequency (Hz):"<< endl;
	cin >> f;

	CoaxXSection coaxXSect(r, R, eps);

	cout << "Z0, Beta = " << coaxXSect.getZ0() << "ohms, "
			<< coaxXSect.getBeta(f) << " rad/m" << endl;
	return 0;
}
