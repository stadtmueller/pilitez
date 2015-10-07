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
#include "Music.h"
#include "Pin.h"
#include <iostream>
#include <wiringPi.h>

#define SIZE 8
#define ISHIGH digitalRead( 29 ) > 0

using namespace std;

int main()
{
  cout << "This program is licensed under GNU GPL. See http://www.gnu.org/licenses/#GPL for more informations" << endl;

  int pins[ SIZE ] = { 0, 2, 3, 21, 22, 23, 24, 25 };

  initPins( pins );

  NoMusic noMusic = NoMusic( pins );

  while( false )
  {
    cout << "1: ";
    noMusic.dualLights2( 2 );

    cout << "2: ";
    noMusic.outIn2();

    cout << "3: ";
    noMusic.strobe( 5 );

    cout << "4: ";
    noMusic.inOut2();

    cout << "5: ";
    noMusic.randomLights( 15 );

    cout << "6: ";
    noMusic.pattern1();

    cout << "7: ";
    noMusic.pattern1( 200 );

    cout << "8: ";
    noMusic.pattern2();

    cout << "9: ";
    noMusic.revDual( 2 );

    cout << "10: ";
    noMusic.revPattern1();

    cout << "11: ";
    noMusic.revPattern2();

    cout << "12: ";
    noMusic.pattern3();

    cout << "13: ";
    noMusic.revPattern3();

    cout << "14: ";
    noMusic.knightRiderLights( 3 );

    cout << "15: ";
    noMusic.vu( 2 );

    cout << "16: ";
    noMusic.redStrobe( 4 );

    cout << "17: ";
    noMusic.blueStrobe( 4 );

    cout << "18: ";
    noMusic.greenStrobe( 4 );

    cout << "19: ";
    noMusic.yellowStrobe( 4 );

    cout << "----------------------------" << endl;
  }

  int i = 0;

  while( true )
  {
    while( i < 4 )
    {
      if( ISHIGH )
      {
        jumpDual();
        delay( 100 );
        i++;
      }
    }
    i = 0;

    while( i < 4 )
    {
      if( ISHIGH )
      {
        jumpRevDual();
        delay( 100 );
        i++;
      }
    }
    i = 0;

    while( i < 10 )
    {
      if( ISHIGH )
      {
        jumpRandomLights();
        delay( 100 );
        i++;
      }
    }

    i = 0;
  }
  return 0;
}
