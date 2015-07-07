/**
* XSectTest.cpp
*   Dana Hughes		07-July-2015
*
* Perorms tests on the various TRLineXSect classes (coax, microstrip, stripline).
*/

#include <iostream>

#include "TRLineXSect.h"
#include "CoaxXSection.h"
#include "MicrostripXSection.h"
#include "StriplineXSection.h"

#include <cmath>

using namespace std;

int main()
{
  // Create four transmission lines -- note we have to upcast these to TRLineXSect pointers

  // Create a Coax with inner radius 2mm, outer radius 10mm, relative permittivity 3.8
  // From http://pasternack.com/t-calculator-coax-cutoff.aspx, the characteristic 
  // impedance should be 49.5 ohms
  //   http://pasternack.com/t-calculator-microstrip.aspx - 49.5 ohms
  //   http://www1.sphere.ne.jp/i-lab/ilab/tool/cx_line_e.htm - 49.54 ohms
  //   http://www.eeweb.com/toolbox/coax - 49.5 ohms

  TRLineXSect* coaxXSect = (TRLineXSect*) new CoaxXSection(.002, 0.01, 3.8);

  // Create a Microstrip with width 5.5mm, height 2.5mm, relative permittivity 3.8 and thickness
  // 1um.  From http://pasternack.com/t-calculator-microstrip.aspx, the impedance should
  // be 49.26 ohms.  Note, though, that this ignores thickness of the strip, so our results
  // may be a little off if we include this (which we should).
  // Also note that this is the case where W/H > 1
  // Other sites give the following results:
  //   http://pasternack.com/t-calculator-microstrip.aspx - 49.26 ohms
  //   http://www1.sphere.ne.jp/i-lab/ilab/tool/ms_line_e.htm - 48.84 ohms
  //   http://www.eeweb.com/toolbox/microstrip-impedance - 48.6 ohms

  TRLineXSect* microstripXSect1 = (TRLineXSect*) new MicrostripXSection(0.0055, 0.0025, 1.0e-6, 3.8);

  // For the case where W/H < 1, use a width of 1.5mm, height of 6.5 mm and relative 
  // permittivity of 3.8, and 1um thickness.  The same site as above gives this impedance as
  // 131.4 ohms
  // Other sites give the following results:
  //   http://pasternack.com/t-calculator-microstrip.aspx - 131.4 ohms
  //   http://www1.sphere.ne.jp/i-lab/ilab/tool/ms_line_e.htm - 131.27 ohms
  //   http://www.eeweb.com/toolbox/microstrip-impedance - 130 ohms

  TRLineXSect* microstripXSect2 = (TRLineXSect*) new MicrostripXSection(0.0015, 0.0065, 1.0e-6, 3.8);

  // Create a Stripline with width 5.5mm, height of 12mm, trace thickness of 1um, and 
  // relative permittivity of 3.8.  http://pasternack.com/t-calculator-stripline.aspx gives
  // the impedance as 50.63 ohms
  // Other sites give the following results:
  //   http://pasternack.com/t-calculator-microstrip.aspx - 50.63 ohms
  //   http://www1.sphere.ne.jp/i-lab/ilab/tool/ms_line_e.htm - 53.96 ohms
  //   http://www.eeweb.com/toolbox/symmetric-stripline-impedance - 52.8 ohms


  TRLineXSect* striplineXSect = (TRLineXSect*) new StriplineXSection(0.0055, 0.012, 1.0e-6, 3.8);

  // Output the results - we'll use eeweb.com's values to calculate error

  cout << "Testing Characteristic Impedance" << endl << endl;
  cout << "COAXIAL" << endl;
  cout << "=======" << endl;
  cout << "  Inner Radius =           2.0mm" << endl;
  cout << "  Outer Radius =          10.0mm" << endl;
  cout << "  Relative Permittivity =  3.8" << endl;
  cout << "  Calculated Impedance  = " << coaxXSect->getZ0() << " ohms" << endl;   
  cout << "  Value from Pasternack   = 49.5 ohms" << endl;
  cout << "  Value from sphere.ne.jp = 49.54 ohms" << endl;
  cout << "  Value from eeweb.com    = 49.5 ohms" << endl;
  cout << endl;


  double coaxZ0error = abs(coaxXSect->getZ0() - 49.5);

  cout << "MICROSTRIP - W/H > 1" << endl;
  cout << "====================" << endl;
  cout << "  Strip Width       =      5.5mm" << endl;
  cout << "  Dielectric Height =      2.5mm" << endl;
  cout << "  Strip Thickness   =      1.0um" << endl;
  cout << "  Relative Permittivity =  3.8" << endl;
  cout << "  Calculated Impedance    = " << microstripXSect1->getZ0() << " ohms" << endl;
  cout << "  Value from Pasternack   = 49.26 ohms" << endl;
  cout << "  Value from sphere.ne.jp = 48.84 ohms" << endl;
  cout << "  Value from eeweb.com    = 48.6 ohms" << endl;
  cout << endl;

  double microstrip1Z0error = abs(microstripXSect1->getZ0() - 48.6);


  cout << "MICROSTRIP - W/H < 1" << endl;
  cout << "====================" << endl;
  cout << "  Strip Width       =      1.5mm" << endl;
  cout << "  Dielectric Height =      6.5mm" << endl;
  cout << "  Strip Thickness   =      1.0um" << endl;
  cout << "  Relative Permittivity =  5.5" << endl;
  cout << "  Calculated Impedance    = " << microstripXSect2->getZ0() << " ohms" << endl;
  cout << "  Value from Pasternack   = 131.4 ohms" << endl;
  cout << "  Value from sphere.ne.jp = 131.27 ohms" << endl;
  cout << "  Value from eeweb.com    = 130.0 ohms" << endl;
  cout << endl;

  double microstrip2Z0error = abs(microstripXSect2->getZ0() - 130.0);

  cout << "STRIPLINE" << endl;
  cout << "=========" << endl;
  cout << "  Strip Width       =      5.5mm" << endl;
  cout << "  Dielectric Height =      6.0mm" << endl;
  cout << "  Strip Thickness   =      1.0um" << endl;
  cout << "  Relative Permittivity =  3.8" << endl;
  cout << "  Calculated Impedance    = " << striplineXSect->getZ0() << " ohms" << endl;
  cout << "  Value from Pasternack   = 50.63 ohms" << endl;
  cout << "  Value from sphere.ne.jp = 53.96 ohms" << endl;
  cout << "  Value from eeweb.com    = 52.8 ohms" << endl;
  cout << endl;

  double striplineZ0error = abs(striplineXSect->getZ0() - 52.8);

  cout << "ERROR" << endl;
  cout << "=====" << endl;
  cout << "  Coax                 - " << coaxZ0error << "\t" << 100*coaxZ0error / 49.5 << "%" << endl; 
  cout << "  Microstrip (W/H > 1) - " << microstrip1Z0error << "\t" << 100*microstrip1Z0error / 48.6 << "%" << endl; 
  cout << "  Microstrip (W/H < 1) - " << microstrip2Z0error << "\t" << 100*microstrip2Z0error / 130.0 << "%" << endl; 
  cout << "  Stripline            - " << striplineZ0error << "\t" << 100*striplineZ0error / 52.8 << "%" << endl; 

  return 0;
}
