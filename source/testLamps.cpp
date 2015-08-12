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


#include <iostream>
#include <wiringPi.h>
#include "functions.h"

using namespace std;

int pins2[ 8 ] = { 0, 2, 3, 21, 22, 23, 24, 25 };

int main()
{
  initPins();
  for( int i : pins2 )
  {
    cout << i << " ist jetzt HIGH" << endl;
    digitalWrite( i, HIGH );

    cout << "Enter-Taste drücken um das nächste Licht zu aktivieren" << endl;

    if( cin.get() == '\n' )
    {
      continue;
    }
  }
  allOf();
}
