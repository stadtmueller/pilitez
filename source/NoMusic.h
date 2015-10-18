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

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

class NoMusic
{
  public:
    NoMusic( std::vector<int> pins_ );
    void randomLights( int cnt );
    void dualLights2( int cnt );
    void revDual( int cnt );
    void outIn2();
    void inOut2();
    void allOn();
    void allOf();
    void knightRiderLights( int cnt );
    void pattern1( long int millis = 400 );
    void revPattern1( long int millis = 400 );
    void pattern2( long int millis = 400 );
    void revPattern2( long int millis = 400 );
    void pattern3();
    void revPattern3();
    void strobe( int cnt );
    void greenStrobe( int cnt );
    void blueStrobe( int cnt );
    void yellowStrobe( int cnt );
    void redStrobe( int cnt );
    void vu( int cnt );
  private:
    std::vector<int> pins;
};

#endif
