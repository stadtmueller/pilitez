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
#include "NoMusic.h"
#include "Pin.h"

using namespace std;

NoMusic::NoMusic( std::vector<Pin> pins_ ):
  pins( pins_ )
  {}


void NoMusic::randomLights( int cnt )
{
  cout << "Random: ";

  int randomNum = 0;
  int last = 0;
  int i = 0;

  while( i < cnt )
  {
    randomNum = (int)myRandom();
    if( randomNum == last )
      continue;
    else
    {
      pins[ randomNum ].set( HIGH );
      delay( 400 );
      pins[ randomNum ].set( LOW );
      last = randomNum;
      i++;
    }
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
      pins[ ix ].set( HIGH );
      pins[ ix + 1 ].set( HIGH );

      delay( 800 );

      pins[ ix ].set( LOW );
      pins[ ix + 1 ].set( LOW );
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
      pins[ ix ].set( HIGH );
      pins[ ix - 1 ].set( HIGH );

      delay( 800 );

      pins[ ix ].set( LOW );
      pins[ ix - 1 ].set( LOW );
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
    pins[ ix ].set( HIGH );
    pins[ ix2 ].set( HIGH );

    delay( 400 );

    pins[ ix ].set( LOW );
    pins[ ix2 ].set( LOW );
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
    pins[ ix ].set( HIGH );
    pins[ ix2 ].set( HIGH );

    delay( 400 );

    pins[ ix ].set( LOW );
    pins[ ix2 ].set( LOW );
    ix++;
    ix2--;
  }
}

void NoMusic::allOn()
{
  //cout << "All on" << endl;

  for( int i = 0; i < SIZE; i++ )
    pins[ i ].set( HIGH );
}

void NoMusic::allOf()
{
  //cout << "Alle off" << endl;

  for( int i = 0; i < SIZE; i++ )
    pins[ i ].set( LOW );
}

void NoMusic::knightRiderLights( int cnt )
{
  cout << "Knight Rider" << endl;

  int i = 0;

  while( i < cnt )
  {
    for( int j = 0; j < SIZE - 1; j++ )
    {
      pins[ j ].set( HIGH );
      delay( 200 );
      if( j != 8 )
        pins[ j ].set( LOW );
    }

    pins[ SIZE ].set( LOW );

    for( int i = SIZE - 1; i >= 0; i-- )
    {
      pins[ i ].set( HIGH );
      delay( 200 );
      pins[ i ].set( LOW );
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
    pins[ 0 + i ].set( HIGH );
    delay( millis );
    pins[ 0 + i ].set( LOW );

    pins[ max - i ].set( HIGH );
    delay( millis );
    pins[ max - i ].set( LOW );
  }
}

void NoMusic::revPattern1( long int millis /* = 400 */ )
{
   cout << "Rev-Pattern 1 @ " << millis << "ms" << endl;

  int max = SIZE - 1;

  for( int i = max / 2; i >= 0; i-- )
  {
    pins[ max - i ].set( HIGH );
    delay( millis );
    pins[ max - i ].set( LOW );

    pins[ 0 + i ].set( HIGH );
    delay( millis );
    pins[ 0 + i ].set( LOW );
  }
}

void NoMusic::pattern2( long int millis )
{
  cout << "Pattern 2 @ " << millis << "ms" << endl;

  int j = 0;
  int i = 2;

  while( i < SIZE )
  {
    pins[ j ].set( HIGH );
    pins[ i ].set( HIGH );
    delay( millis );
    pins[ j ].set( LOW );
    pins[ i ].set( LOW );
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
    pins[ j ].set( HIGH );
    pins[ i ].set( HIGH );
    delay( millis );
    pins[ j ].set( LOW );
    pins[ i ].set( LOW );
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
    pins[ ix ].set( HIGH );
    pins[ ix + 1].set( HIGH );

    delay( 400 );

    pins[ ix ].set( LOW );
    pins[ ix + 1 ].set( LOW );
    ix++;
  }
}

void NoMusic::revPattern3()
{
  cout << "Rev-Pattern 3" << endl;

  int ix = SIZE -1;

  while( ix >= -1 )
  {
     pins[ ix ].set( HIGH );
     pins[ ix - 1 ].set( HIGH );

     delay( 400 );

     pins[ ix ].set( LOW );
     pins[ ix - 1].set( LOW );
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
      pins[ ix ].set( HIGH );
      pins[ ix2 ].set( HIGH );
      delay( 100 );
      ix--;
      ix2++;
    }

    while( ix2 >= (SIZE / 2) )
    {
      pins[ ix ].set( LOW );
      pins[ ix2 ].set( LOW );
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
    pins[ 3 ].set( HIGH );
    pins[ 4 ].set( HIGH );
    delay( 100 );
    pins[ 3 ].set( LOW );
    pins[ 4 ].set( LOW );
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
    pins[ 2 ].set( HIGH );
    pins[ 5 ].set( HIGH );
    delay( 100 );
    pins[ 2 ].set( LOW );
    pins[ 5 ].set( LOW );
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
    pins[ 1 ].set( HIGH );
    pins[ 6 ].set( HIGH );
    delay( 100 );
    pins[ 1 ].set( LOW );
    pins[ 6 ].set( LOW );
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
    pins[ 0 ].set( HIGH );
    pins[ 7 ].set( HIGH );
    delay( 100 );
    pins[ 0 ].set( LOW );
    pins[ 7 ].set( LOW );
    delay( 100 );
    i++;
  }
}

void NoMusic::toggledRandom( int cnt )
{
  cout << "Toggled Random: ";

  int pin = 0;
  int i = 0;

  while( i < cnt )
  {
    pin = (int)myRandom();

    pins[ pin ].toggle();

    delay( 400 );

    i++;
  }

  allOf();

  cout << std::endl;
}
