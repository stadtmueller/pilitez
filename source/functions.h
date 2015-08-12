#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define SIZE 8

void initPins();
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

void music();

#endif
