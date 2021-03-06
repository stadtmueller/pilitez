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

#ifndef PIN_H
#define PIN_H

#include <vector>

#define SIZE 8

class Pin
{
  public:
    Pin( int number );       // Constructor with wiringPi pin number
    int getNumber();         // getNumber(): Returns the wiringPi number of that Pin
    bool getState();         // getState():  Returns either true( pin is HIGH ) or false( pin is LOW )
    void set( bool isHigh ); // set():       Sets a state( high=true:HIGH -- high=false:LOW ) ( Output pins only )
    void toggle();           // toggle():    If the pin is HIGH it will be set to LOW, if it is LOW it will be HIGH
  private:
    int number_;
    bool state;
};


std::vector<Pin> initPins();
long int myRandom();


#endif
