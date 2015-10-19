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

#ifndef JUMPFUNCTIONS_H
#define JUMPFUNCTIONS_H

#include <vector>
#include "Pin.h"

class Music
{
  public:
    Music( std::vector<Pin> pins_ );
    void jumpDual();
    void jumpRevDual();
    void jumpRandomLights();
  private:
    std::vector<Pin> pins;
};

#endif
