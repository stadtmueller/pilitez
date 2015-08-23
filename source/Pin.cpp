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

#include "Pin.h"
#include <wiringPi.h>

void initPins( int pins[] )
{
  cout << "Init..." << endl;

  wiringPiSetup();
  system( "gpio edge 29 rising" );

  for( int i : pins )
    pinMode( i, OUTPUT );          // <-- Add "Pin"-call here and buffer it in array

  cout << "Init done" << endl << endl;
}


Pin::Pin( int number ):
  number_( number )
  {
    pinMode( this->number_, OUTPUT );
    this->state = false;
  }

int Pin::getNumber()
{
  return this->number;
}

bool Pin::getState()
{
  return this->state;
}

void Pin::set( bool high )
{
  if( high )
    digitalWrite( this->number_, HIGH );
  else
    digitalWrite( this->number_, LOW );
}
