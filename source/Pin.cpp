#include "Pin.h"

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
