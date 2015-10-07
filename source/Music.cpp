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
#include "Pin.h"

using namespace std;

int pins[ SIZE ] = { 0, 2, 3, 21, 22, 23, 24, 25 };

void jumpDual()
{
  static int ix = -2;

  if( ix == SIZE )
  {
    ix = 0;
  }

  digitalWrite( pins[ ix ], LOW );
  digitalWrite( pins[ ix + 1 ], LOW );

  digitalWrite( pins[ ix + 2 ], HIGH );
  digitalWrite( pins[ ix + 3 ], HIGH );
  ix += 2;
}

void jumpRevDual()
{
  static int ix = SIZE + 1;

  digitalWrite( pins[ ix ], LOW );
  digitalWrite( pins[ ix - 1 ], LOW );

  digitalWrite( pins[ ix - 2 ], HIGH );
  digitalWrite( pins[ ix - 3 ], HIGH );


  if( ix == 1 )
  {
    ix = SIZE + 1;
  }

  ix -= 2;
}

void jumpRandomLights()
{
  static int lastIx = 0;

  digitalWrite( pins[ lastIx ], LOW );

  lastIx = myRandom();

  digitalWrite( pins[ lastIx ], HIGH );
}
