#include "Pin.h"
#include <wiringPi.h>

Pin::Pin( int number ):
  number_( number )
  {
    this.state = false;
  }

int Pin::getNumber()
{
  return this.number;
}

bool Pin::getState()
{
  return this.state;
}

void Pin::set( bool high )
{
  if( high )
    digitalWrite( this->number_, HIGH );
  else
    digitalWrite( this->number_, LOW );
}
