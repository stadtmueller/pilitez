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
#include <iostream>
#include <random>

using namespace std;

pins = {  0, 2, 3, 21, 22, 23, 24, 25 };


void initPins( int pins[] )
{
  cout << "Init..." << endl;

  wiringPiSetup();
  system( "gpio edge 29 rising" );

  for( int i = 0; i < SIZE; i++ )
    pinMode( pins[ i ], OUTPUT );         // <-- Add "Pin"-call here and buffer it in array

  cout << "Init done" << endl << endl;
}

long int myRandom()
{
  random_device rd;
  mt19937 eng( rd() );
  uniform_int_distribution<> distr( 0, SIZE );
  int num = distr( eng );
  cout << num << " ";

  return num;
}



Pin::Pin( int number ):
  number_( number )
  {
    pinMode( this->number_, OUTPUT );
    this->state = false;
  }

int Pin::getNumber()
{
  return this->number_;
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
