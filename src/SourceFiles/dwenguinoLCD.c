/*
 * dwenguinoLCD.c
 *
 *  Created on: Jan 19, 2016
 *      Author: Tom Neutens
 */

#include "../HeaderFiles/dwenguinoLCD.h"
#include <stdlib.h>

//	Keeps track of current line number and character position.
struct lcd_info_type lcd_info;

void initLCD(void){
	LCD_BACKLIGHT_OUT;	//	Set LCD backlight als output.

	_delay_ms(5);

	LCD_DATA_DIR = PORT_LOW;	//	Set port as input
	LCD_DATA = 0;

	LCD_RS_OUT;
	LCD_RW_OUT;
	LCD_EN_OUT;

	LCD_RS_LOW;
	LCD_RW_LOW;
	LCD_EN_LOW;

	_delay_ms(15);

	LCD_DATA_DIR = PORT_HIGH;	//set port as output

	commandLCD(0b00110000);
	commandLCD(0b00110000);
	commandLCD(0b00110000);
	commandLCD(0b00111000);
	commandLCD(0b00000110);
	commandLCD(0b00011000);
	commandLCD(0b00001100);
	lcd_info.line = lcd_info.pos = 0;

}

void clearLCD(void){
	commandLCD(0b00000001);
	_delay_ms(2);
	setCursorLCD(0, 0);
}

void commandLCD(const BYTE c) {
	BYTE temp;

	temp = LCD_DATA;		//	Save the current state on datapins for LED's

	//	Write command to LCD
	LCD_RW_LOW;
	LCD_RS_LOW;

	LCD_EN_HIGH;				//	Bring the enable pin high
	//temp = LCD_DATA;			//	Save the current data on datapins for LED's
	LCD_DATA = c;				//	Write command data to data port
	LCD_EN_LOW;				//	Data is clocked at falling edge of enable pin
	LCD_DATA = temp;			//	Restore data on datapins
	_delay_us(45);				//	Wait until display has processed the data

}

void dataLCD(const BYTE c){
	BYTE temp;

	temp = LCD_DATA;		//	Save the current state on datapins for LED's

	//	Write command to LCD
	LCD_RW_LOW;
	LCD_RS_HIGH;				

	LCD_EN_HIGH;				//	Bring the enable pin high
	//temp = LCD_DATA;			//	Save the current data on datapins for LED's
	LCD_DATA = c;				//	Write command data to data port
	LCD_EN_LOW;				//	Data is clocked at falling edge of enable pin
	LCD_DATA = temp;			//	Restore data on datapins
	_delay_us(45);				//	Wait until display has processed the data
}

void setCursorLCD(BYTE l, BYTE p) {
	BYTE c;

	// check if input is valid
	if (l>LCD_LASTLINE) l = LCD_LASTLINE;
	if (p>LCD_LASTPOS)  p = LCD_LASTPOS;

	lcd_info.line = l;
	lcd_info.pos = p;

	if (l == 1)
		c = 0b11000000;
	else
		c = 0b10000000;

	// position offset
	p &= 0b00001111;
	c |= p;

	commandLCD(c);

	_delay_us(45);         // wait until display has processed the command
}


void appendCharToLCD(const char c) {
  unsigned temp = LCD_DATA;   // Save current data on datapins for LED's
  if (lcd_info.pos>LCD_LASTPOS)
    if (lcd_info.line)
      clearLCD();
    else
      setCursorLCD(1, 0);

	// Write char to LCD
  	LCD_RW_LOW;
  	LCD_RS_HIGH;

	LCD_EN_HIGH;      // Bring enable pin high
	temp = LCD_DATA;      // Save current data on datapins for LED's
	LCD_DATA   = c;       // Write data to data port
	LCD_EN_LOW;       // data is clocked at the falling edge of enable pin
	LCD_DATA   = temp;    // restore data on datapins
	_delay_us(45);         // wait until display has processed the data

	lcd_info.pos++;       // increment lcd cursor position
}


void printCharToLCD(const char c, BYTE l, BYTE p) {
	BYTE temp;

	// set cursor to selected position
	setCursorLCD(l,p);

	// append to this position
	appendCharToLCD(c);
}

void appendStringToLCD_(const char* message) {
	while (*message) {
		appendCharToLCD(*message++);
	}
}

void printStringToLCD(char* message, BYTE l, BYTE p) {
	// set cursor to selected position
	setCursorLCD(l,p);

	// append to this position
	appendStringToLCD(message);
}

void appendStringToLCDcharptr(char* message) {
  while(*message) {
    appendCharToLCD(*message++);
  }
}

void appendIntToLCD(int i) {
  char buffer[7];
  itoa(i,buffer, 10);
  buffer[6] = 0;
  appendStringToLCDcharptr(buffer);
}

void printIntToLCD(int i, BYTE l, BYTE p) {
	// set cursor to selected position
	setCursorLCD(l,p);

	// append to this position
	appendIntToLCD(i);
}

//added by us (Antoine and Sebastiaan)
void appendUintToLCD(unsigned int i) {
  char buffer[7];
  utoa(i,buffer, 10);
  buffer[6] = 0;
  appendStringToLCDcharptr(buffer);
}

void printUintToLCD(unsigned int i, BYTE l, BYTE p) {
	// set cursor to selected position
	setCursorLCD(l,p);

	// append to this position
	appendUintToLCD(i);
}
