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
#include "Music.h"
#include <wiringPi.h>

using namespace std;

Music::Music( std::vector<Pin> pins_ ):
  pins( pins_ );
  {}


void Music::jumpDual()
{
  static int ix = -2;

  if( ix == SIZE )
  {
    ix = 0;
  }

  pins[ ix ].set( LOW );
  pins[ ix + 1 ].set( LOW );

  pins[ ix + 2 ].set( HIGH );
  pins[ ix + 3 ].set( HIGH );
  ix += 2;
}

void Music::jumpRevDual()
{
  static int ix = SIZE + 1;

  pins[ ix ].set( LOW );
  pins[ ix - 1 ].set( LOW );

  pins[ ix - 2 ].set( HIGH );
  pins[ ix - 3 ].set( HIGH );


  if( ix == 1 )
  {
    ix = SIZE + 1;
  }

  ix -= 2;
}

void Music::jumpRandomLights()
{
  static int lastIx = 0;

  pins[ lastIx ].set( LOW );

  lastIx = myRandom();

  pins[ lastIx ].set( HIGH );
}
