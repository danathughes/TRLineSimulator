/*
 * TRTest.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: sarahradzihovsky
 */

#include "TRLinesTotal.h"
#include "TRLineXSect.h"
#include "TRLine.h"
#include "CoaxXSection.h"
#include "StriplineXSection.h"
#include "MicrostripXSection.h"
#include <iostream>
#include <math.h>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

/* Function Prototypes */

TRLineXSect* getXSect(string type, double f);
vector <TRLine> makeTRLineVector(TRLine sum);
vector <int> makeLengthsVector(double l);

int main() {

	cout << "This program allows you to find characteristics of TRXSections, TRLine "
			"segments, and entire TRLines given the parameters you choose." << endl;

	/*User chooses what they would like to calculate*/
	string calcType = "";
	cout << "What would you like to calculate? ((1)XSection (2)Line Segment (3)Entire Line)" << endl;
	cin >> calcType;

	/*Only runs code in if statement if XSection or Line Segment is being calculated*/
	if (calcType == "1" || calcType == "2"){

		/*User chooses what type of XSection they would like to find values for*/
		string type = "";
		cout << "Type of XSection? ((1)Microstrip, (2)Stripline, (3)Coax)" << endl;
		cin >> type;

		/*Given f and XSection dimensions, ZO and Beta (phase constant) is found.*/
		double f;
		cout << "Frequency (Hz):"<< endl;
		cin >> f;

		TRLineXSect *trXSect = NULL;
		trXSect = getXSect(type, f);

		/*Outputs Z0 and Beta of chosen XSection*/
		cout << "Z0, Beta = "  << trXSect -> getZ0() << "ohms, "
				<< trXSect -> getBeta(f) << " rad/m" << endl;

		/*Ends program here if user only wanted to calculate values of a single XSection*/
		if (calcType == "1") {
			return 0;
		}

		/*Given length and load impedance, inner impedance and reflection coeff is found*/
		double l;
		complex <double> zLoad;
		cout << "Load Impedance (ohms):" << endl;
		cin >> zLoad;
		cout << "Length (m):" << endl;
		cin >> l;

		TRLine sum = TRLine (zLoad, trXSect, l);

		/*Outputs Zin and reflection coeff of chosen TRLine segment*/
		cout << "Inner Impedance (ohms), Reflection Coefficient = " << sum.getZin(f)
																		<< ", " << sum.getGamma() << endl;

		/*Ends program here if user only wanted to calculate values of a single TRLine segment*/
		if (calcType == "2"){
			return 0;
		}
	}

	cout << "Start by First cross-section should be the one closest to zLoad. Each one "
			"following should be the next consecutive segment when moving away"
			" from zLoad." << endl;

	/*Only runs this code if entire TRLine is being calculated*/
	double f;
	double l;
	complex <double> zLoad;
	vector <TRLine> TRLines;
	vector <int> lengths;

	cout << "Frequency (Hz):"<< endl;
	cin >> f;

	/*Will keep adding TRLine segments to the line until user declares "yes" they are finished.*/
	string input = "";
	while (input != "yes"){

		/*User chooses what type of XSection they would like to find values for*/
		string type = "";
		cout << "Type of XSection? ((1)Microstrip, (2)Stripline, (3)Coax)" << endl;
		cin >> type;

		TRLineXSect *trXSect = NULL;
		trXSect = getXSect(type, f);

		/*Outputs Z0 and Beta of chosen XSection*/
		cout << "Z0, Beta = "  << trXSect -> getZ0() << "ohms, "
				<< trXSect -> getBeta(f) << " rad/m" << endl;

		/*Given length and load impedance, inner impedance and reflection coeff is found*/
		cout << "Load Impedance (ohms):" << endl;
		cin >> zLoad;
		cout << "Length (m):" << endl;
		cin >> l;

		TRLine sum = TRLine (zLoad, trXSect, l);

		cout << "Inner Impedance (ohms), Reflection Coefficient = " << sum.getZin(f)
																	<< ", " << sum.getGamma() << endl;

		/*Creates 2 vectors containing TRLine segments and length of segments respectively*/
		TRLines = makeTRLineVector(sum);
		lengths = makeLengthsVector(l);

		/*
		 * After adding each segment to the TRLine, program asks user whether that
		 * segment is the last one or whether the user would like to add more.
		 */
		cout << "Finished? (yes/no)" << endl;
		cin >> input;
	}

	TRLinesTotal total(TRLines, lengths, zLoad);

	cout << "Zin (ohms), Reflection Coefficient = " << total.getZinTotal(f)
														<< ", " << total.getGammaTotal(f) << endl;

	return 20;
}


/*
 *  Finds desired trXSect based on dimensions chosen by user
 * (includes Z0 and Beta).
 */
TRLineXSect* getXSect(string type, double f){
	double r, R, eps, w, h, t, b;
	TRLineXSect *trXSect = NULL;

	/*If calculating microstrip Xsect, takes in width, height, strip thickness, and permittivity*/
	if (type == "1"){
		/*for microstrip*/
		cout << "Width (m):"<< endl;
		cin >> w;
		cout << "Height (m):"<< endl;
		cin >> h;
		cout << "Thinkness of Inner Strip (m):"<< endl;
		cin >> t;
		cout << "Permittivity:"<< endl;
		cin >> eps;

		return trXSect = new MicrostripXSection (w, h, t, eps);

		/*If calculating stripline Xsect, takes in width, height, strip thickness, and permittivity*/
	} else if (type == "2"){
		/*for stripline*/
		cout << "Width (m):"<< endl;
		cin >> w;
		cout << "Height (m):"<< endl;
		cin >> b;
		cout << "Thinkness of Inner Strip (m):"<< endl;
		cin >> t;
		cout << "Permittivity:"<< endl;
		cin >> eps;

		return trXSect = new StriplineXSection (w, b, t, eps);

		/*If calculating coax Xsect, takes in the inner & outer radius and permittivity*/
	} else if (type == "3") {
		/* for coax*/
		cout << "Small Radius (m):"<< endl;
		cin >> r;
		cout << "Large Radius (m):"<< endl;
		cin >> R;
		cout << "Permittivity:"<< endl;
		cin >> eps;

		return trXSect = new CoaxXSection (r, R, eps);
	}
}

/*
 * Adds TRLine segments to this vector starting with the segment next to the load
 * impedance and continuing through the rest of the segments consecutively
 */
vector <TRLine> makeTRLineVector(TRLine sum){
	vector <TRLine> TRLines;
	TRLines.push_back(sum);
	return TRLines;
}

/*Adds the lengths corresponding to the TRLine segments in TRLines*/
vector <int> makeLengthsVector(double l){
	vector <int> lengths;
	lengths.push_back(l);
	return lengths;
}


//string makeCaseInsensitive(string answer){
//	for (int i = 0; i < answer.length(); i++){
//		answer.at(i) = tolower(answer.at(i));
//	}
//	return answer;
//}
