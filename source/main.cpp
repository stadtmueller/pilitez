#include "functions.h"
#include <iostream>
#include <wiringPi.h>

using namespace std;

int main()
{
  initPins();

  while( true )
  {
    cout << "1: ";
    dualLights2( 2 );

    cout << "2: ";
    outIn2();

    cout << "3: ";
    strobe( 5 );

    cout << "4: ";
    inOut2();

    cout << "5: ";
    randomLights( 15 );

    cout << "6: ";
    pattern1();

    cout << "7: ";
    pattern1( 200 );

    cout << "8: ";
    pattern2();

    cout << "9: ";
    revDual( 2 );

    cout << "10: ";
    revPattern1();

    cout << "11: ";
    revPattern2();

    cout << "12: ";
    pattern3();

    cout << "13: ";
    revPattern3();

    cout << "14: ";
    knightRiderLights( 3 );

    cout << "15: ";
    vu( 2 );

    cout << "16: ";
    redStrobe( 4 );

    cout << "17: ";
    blueStrobe( 4 );

    cout << "18: ";
    greenStrobe( 4 );

    cout << "19: ";
    yellowStrobe( 4 );

    cout << "----------------------------" << endl;
  }
  return 0;
}
