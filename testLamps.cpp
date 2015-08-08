#include <iostream>
#include <wiringPi.h>
#include "functions.h"

using namespace std;

int pins2[ 8 ] = { 0, 2, 3, 21, 22, 23, 24, 25 };

int main()
{
  initPins();
  for( int i : pins2 )
  {
    cout << i << " ist jetzt HIGH" << endl;
    digitalWrite( i, HIGH );

    cout << "Enter-Taste drücken um das nächste Licht zu aktivieren" << endl;

    if( cin.get() == '\n' )
    {
      continue;
    }
  }
  allOf();
}
