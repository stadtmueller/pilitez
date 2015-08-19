/*
This file is part of PiLitez.

    PiLitez is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PiLitez is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PiLitez.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "NoMusic.h"
#include <iostream>
#include <wiringPi.h>

using namespace std;

void initPins()
{
  cout << "Init..." << endl;

  wiringPiSetup();

  for( int i : pins )
    pinMode( i, OUTPUT );

  system( "gpio edge 29 rising" );

  cout << "Init done" << endl << endl;
}

int main()
{
  cout << "This program is licensed under GNU GPL. See http://www.gnu.org/licenses/#GPL for more informations" << endl;

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
