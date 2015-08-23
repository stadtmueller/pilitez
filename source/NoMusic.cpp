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
#include <random>
#include <wiringPi.h>
#include "NoMusic.h"
#include "Pin.h"

using namespace std;

int pins[ SIZE ] = { 0, 2, 3, 21, 22, 23, 24, 25 };

long int random()
{
  random_device rd;
  mt19937 eng( rd() );
  uniform_int_distribution<> distr( 0, SIZE );
  int num = distr( eng );
  cout << num << " ";

  return num;
}

NoMusic::NoMusic( int pins_[] ):
  pins( pins_ )
  {}

void NoMusic::randomLights( int cnt )
{
  cout << "Random: ";

  int randomNum = 0;
  int last = 0;
  int currentPin = 0;
  int i = 0;

  while( i < cnt )
  {
    randomNum = (int)random();
    if( randomNum == last )
      continue;
    else
      currentPin = pins[ randomNum ];
    digitalWrite( currentPin, HIGH );
    delay( 400 );
    digitalWrite( currentPin, LOW );
    last = randomNum;
    i++;
  }
  cout << endl;
}

void NoMusic::dualLights2( int cnt )
{
  cout << "Dual" << endl;
  int ix = 0;
  int i = 0;

  while( i < cnt )
  {
    while( ix < SIZE )
    {
      digitalWrite( pins[ ix ], HIGH );
      digitalWrite( pins[ ix + 1 ], HIGH );

      delay( 800 );

      digitalWrite( pins[ ix ], LOW );
      digitalWrite( pins[ ix + 1 ], LOW );
      ix += 2;
    }
    ix = 0;
    i++;
  }
}

void NoMusic::revDual( int cnt )
{
  cout << "Rev-Dual" << endl;
  int ix = SIZE - 1;
  int i = 0;

  while( i < cnt )
  {
    while( ix > 0 )
    {
      digitalWrite( pins[ ix ], HIGH );
      digitalWrite( pins[ ix - 1 ], HIGH );

      delay( 800 );

      digitalWrite( pins[ ix ], LOW );
      digitalWrite( pins[ ix - 1 ], LOW );
      ix -= 2;
    }
    ix = SIZE - 1;
    i++;
  }
}



void NoMusic::outIn2()
{
  cout << "Outside Inside" << endl;

  int ix = 0;
  int ix2 = SIZE - 1;

  while( ix < ( SIZE / 2 ) )
  {
    digitalWrite( pins[ ix ], HIGH );
    digitalWrite( pins[ ix2 ], HIGH );

    delay( 400 );

    digitalWrite( pins[ ix ], LOW );
    digitalWrite( pins[ ix2 ], LOW );
    ix++;
    ix2--;
  }
}

void NoMusic::inOut2()
{
  cout << "Inside Outside" << endl;
  int ix = SIZE / 2;
  int ix2 = ( SIZE / 2 ) - 1;

  while( ix < SIZE )
  {
    digitalWrite( pins[ ix ], HIGH );
    digitalWrite( pins[ ix2 ], HIGH );

    delay( 400 );

    digitalWrite( pins[ ix ], LOW );
    digitalWrite( pins[ ix2 ], LOW );
    ix++;
    ix2--;
  }
}

void NoMusic::allOn()
{
  //cout << "All on" << endl;

  for( int i : pins )
    digitalWrite( i, HIGH );
}

void NoMusic::allOf()
{
  //cout << "Alle off" << endl;

  for( int i : pins )
    digitalWrite( i, LOW );
}

void NoMusic::knightRiderLights( int cnt )
{
  cout << "Knight Rider" << endl;

  int i = 0;

  while( i < cnt )
  {
    for( int j = 0; j < SIZE - 1; j++ )
    {
      digitalWrite( pins[ j ], HIGH );
      delay( 200 );
      if( j != 8 )
        digitalWrite( pins[ j ], LOW );
    }

    digitalWrite( pins[ SIZE ], LOW );

    for( int i = SIZE - 1; i >= 0; i-- )
    {
      digitalWrite( pins[ i ], HIGH );
      delay( 200 );
      digitalWrite( pins[ i ], LOW );
    }
    i++;
  }
}

void NoMusic::pattern1( long int millis )
{
  cout << "Pattern 1 @ " << millis << "ms" << endl;

  int max = SIZE - 1;

  for( int i = 0; i <= max / 2; i++ )
  {
    digitalWrite( pins[ 0 + i ], HIGH );
    delay( millis );
    digitalWrite( pins[ 0 + i ], LOW );

    digitalWrite( pins[ max - i ], HIGH );
    delay( millis );
    digitalWrite( pins[ max - i ], LOW );
  }
}

void NoMusic::revPattern1( long int millis /* = 400 */ )
{
   cout << "Rev-Pattern 1 @ " << millis << "ms" << endl;

  int max = SIZE - 1;

  for( int i = max / 2; i >= 0; i-- )
  {
    digitalWrite( pins[ max - i ], HIGH );
    delay( millis );
    digitalWrite( pins[ max - i ], LOW );

    digitalWrite( pins[ 0 + i ], HIGH );
    delay( millis );
    digitalWrite( pins[ 0 + i ], LOW );
  }
}

void NoMusic::pattern2( long int millis )
{
  cout << "Pattern 2 @ " << millis << "ms" << endl;

  int j = 0;
  int i = 2;

  while( i < SIZE )
  {
    digitalWrite( pins[ j ], HIGH );
    digitalWrite( pins[ i ], HIGH );
    delay( millis );
    digitalWrite( pins[ j ], LOW );
    digitalWrite( pins[ i ], LOW );
    j++;
    i++;
  }
}

void NoMusic::revPattern2( long int millis )
{
  cout << "Rev-Pattern 2 @ " << millis << "ms" << endl;

  int j = SIZE - 1;
  int i = j - 2;

  while( i >= 0 )
  {
    digitalWrite( pins[ j ], HIGH );
    digitalWrite( pins[ i ], HIGH );
    delay( millis );
    digitalWrite( pins[ j ], LOW );
    digitalWrite( pins[ i ], LOW );
    j--;
    i--;
  }
}

void NoMusic::pattern3()
{
  cout << "Pattern 3" << endl;

  int ix = -1;

  while( ix <= SIZE )
  {
    digitalWrite( pins[ ix ], HIGH );
    digitalWrite( pins[ ix + 1], HIGH );

    delay( 400 );

    digitalWrite( pins[ ix ], LOW );
    digitalWrite( pins[ ix + 1 ], LOW );
    ix++;
  }
}

void NoMusic::revPattern3()
{
  cout << "Rev-Pattern 3" << endl;

  int ix = SIZE -1;

  while( ix >= -1 )
  {
     digitalWrite( pins[ ix ], HIGH );
     digitalWrite( pins[ ix - 1 ], HIGH );

     delay( 400 );

     digitalWrite( pins[ ix ], LOW );
     digitalWrite( pins[ ix - 1], LOW );
     ix--;
  }
}

void NoMusic::strobe( int cnt )
{
  cout << "Strobe" << endl;

  int i = 0;

  while( i <= cnt )
  {
    allOn();
    delay( 100 );
    allOf();
    delay( 100 );
    i++;
  }
}

void NoMusic::vu( int cnt )
{
  cout << "VU" << endl;

  int ix = 0;
  int ix2 = 0;
  int i = 0;

  while( i <= cnt )
  {
    ix = (SIZE / 2) - 1;
    ix2 = SIZE / 2;

    while( ix >= 0 )
    {
      digitalWrite( pins[ ix ], HIGH );
      digitalWrite( pins[ ix2 ], HIGH );
      delay( 100 );
      ix--;
      ix2++;
    }

    while( ix2 >= (SIZE / 2) )
    {
      digitalWrite( pins[ ix ], LOW );
      digitalWrite( pins[ ix2 ], LOW );
      delay( 100 );
      ix2--;
      ix++;
    }
    i++;
  }
}

void NoMusic::blueStrobe( int cnt )
{
  cout << "Blue Strobe" << endl;

  int i = 0;
  while( i < cnt )
  {
    digitalWrite( pins[ 3 ], HIGH );
    digitalWrite( pins[ 4 ], HIGH );
    delay( 100 );
    digitalWrite( pins[ 3 ], LOW );
    digitalWrite( pins[ 4 ], LOW );
    delay( 100 );
    i++;
  }
}

void NoMusic::greenStrobe( int cnt )
{
  cout << "Green Strobe" << endl;

  int i = 0;
  while( i < cnt )
  {
    digitalWrite( pins[ 2 ], HIGH );
    digitalWrite( pins[ 5 ], HIGH );
    delay( 100 );
    digitalWrite( pins[ 2 ], LOW );
    digitalWrite( pins[ 5 ], LOW );
    delay( 100 );
    i++;
  }
}

void NoMusic::yellowStrobe( int cnt )
{
  cout << "Yellow Strobe" << endl;
  int i = 0;
  while( i < cnt )
  {
    digitalWrite( pins[ 1 ], HIGH );
    digitalWrite( pins[ 6 ], HIGH );
    delay( 100 );
    digitalWrite( pins[ 1 ], LOW );
    digitalWrite( pins[ 6 ], LOW );
    delay( 100 );
    i++;
  }
}

void NoMusic::redStrobe( int cnt )
{
  cout << "Red Strobe" << endl;

  int i = 0;
  while( i < cnt )
  {
    digitalWrite( pins[ 0 ], HIGH );
    digitalWrite( pins[ 7 ], HIGH );
    delay( 100 );
    digitalWrite( pins[ 0 ], LOW );
    digitalWrite( pins[ 7 ], LOW );
    delay( 100 );
    i++;
  }
}
