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

#include "Music.h"
#include <wiringPi.h>

using namespace std;

Music::Music( int pins_[] )
{
  for( int i = 0; i < SIZE; i++ )
    this->pins[ i ] = pins_[ i ];
}

void Music::jumpDual()
{
  static int ix = -2;

  if( digitalRead( 29 ) > 0 )
  {
    if( ix <= SIZE )
    {
      digitalWrite( pins[ ix ], LOW );
      digitalWrite( pins[ ix + 1 ], LOW );

      digitalWrite( pins[ ix + 2 ], HIGH );
      digitalWrite( pins[ ix + 3 ], HIGH );
    }
    ix += 2;
  }
}

