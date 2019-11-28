/**
*\file dwenguinoIO.c
*\author Antoine, Sebastiaan
*/

#include "../HeaderFiles/dwenguinoIO.h"

void initLED(){
  DDRA = 0xFF;
  PORTA = 0b11111111;
}

void initButtons(){
  DDRE &= ~_BV(PINE4) & ~_BV(PINE5) & ~_BV(PINE6);
  PORTE |= _BV(PINE4) & _BV(PINE5) & _BV(PINE6);
  EIMSK |= _BV(INT4);
  EIMSK |= _BV(INT5);
  EIMSK |= _BV(INT6);
  EICRB &= ~_BV(ISC40);
  EICRB |= _BV(ISC41);
  EICRB &= ~_BV(ISC50);
  EICRB |= _BV(ISC51);
  EICRB &= ~_BV(ISC60);
  EICRB |= _BV(ISC61);
  SREG |= _BV(SREG_I);
}
