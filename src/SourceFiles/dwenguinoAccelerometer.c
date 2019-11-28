/*!
* \file dwenguinoAccelerometer.c
* \author Antoine, Sebastiaan
*/

#include "../HeaderFiles/dwenguinoAccelerometer.h"

#include <stdlib.h>


void error(){
  printStringToLCD("ERROR           ", 0, 0);
  printStringToLCD("CHECK PWR CABLE ", 1, 0);
}




void initAccelerometer(){
  //enable 2-wire serial interface (p211)
  PRR0 &= ~_BV(PRTWI);
  //send START condition
  TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN);
  //wait for START accepted
  while(!(TWCR & (1<<TWINT))){
  }

  //TWSR values see table 21.3 p227 of Dwenguino datasheet
  if((TWSR & 0xF8) != 0x08){
    error();
  }
  //load address accelerometer (SLA_W)
  TWDR= 0b11010000;
  //set TWINT = 1, start transmission
  TWCR = (1<<TWINT) | (1<<TWEN);
  while(!(TWCR & (1<<TWINT))){
    //printCharToLCD('a',1,1);
  }

  if((TWSR & 0xF8) != 0x18){
    error();
  }

  TWDR = 0x6B;
  TWCR = (1<<TWINT) | (1<<TWEN);
  while(!(TWCR & (1<<TWINT))){
  }

  if((TWSR & 0xF8) != 0x28){
    error();
  }

  //set 0x6B = PWR_MGMT to 0 (p41 in accelerometer registersheet)
  TWDR = 0b00000000;
  TWCR = (1<<TWINT) | (1<<TWEN);
  while(!(TWCR & (1<<TWINT))){
    //printCharToLCD('c',1,1);
  }

  if((TWSR & 0xF8) != 0x28){
    error();
  }
  //STOP condition
  TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);

}


int read(int reg){
  TWCR=0;
  //send START condition
  TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN);
  //wait for START accepted
  while(!(TWCR & _BV(TWINT))){
  }

  if((TWSR & 0xF8) != 0x08){
    error();
  }

  //load address accelerometer (SLA_W)
  TWDR= 0b11010000;
  //set TWINT = 1, start transmission
  TWCR = _BV(TWINT) | _BV(TWEN);
  while(!(TWCR & _BV(TWINT))){
  }

  if((TWSR & 0xF8) != 0x18){
    error();
  }
  //send register to read
  TWDR = reg;
  TWCR = _BV(TWINT) | _BV(TWEN);
  while(!(TWCR & _BV(TWINT))){
  }

  if((TWSR & 0xF8) != 0x28){
    error();
  }

  //send repeated START condition
  TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN);
  while(!(TWCR & _BV(TWINT))){
  }


  if((TWSR & 0xF8) != 0x10){
    error(8);
  }
  
  //SLA_R
  TWDR= 0b11010001;
  TWCR = _BV(TWINT) | _BV(TWEN);
  while(!(TWCR & _BV(TWINT))){
  }

  TWDR = reg;
  TWCR = _BV(TWINT) | _BV(TWEN);
  while(!(TWCR & _BV(TWINT))){
  }

  //send STOP condition
  TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWSTO);

  return TWDR;
 }

int readX(){
  int high = read(0x3B);
  int low = read(0x3C);
  return (high<<8)|low;
}
int readY(){
  int high = read(0x3D);
  int low = read(0x3E);
  return (high << 8)|low;
}
int readZ(){
  int high = read(0x3F);
  unsigned int low = read(0x40);
  return (high<<8|low);
}

int readPitch(){
  int Gx = readX();
  int Gz = readZ();
  return atan2(-Gx,Gz)*57.3; //57,3 ~= 180/Pi
}


int readRoll(){
  int Gy = readY();
  int Gz = readZ();
  return atan2(Gy,Gz)*57.3; //57,3 ~= 180/Pi
}
