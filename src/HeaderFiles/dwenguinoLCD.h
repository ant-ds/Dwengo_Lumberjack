/*!
* \file dwenguinoLCD.h
* \brief Enables basic print to LCD functionality.
*
* This function was prewritten for the project and has been slightly altered. The altered/added functions are annotated.
* \author Tom Neutens
* \date Jan 19, 2016
*/

#ifndef DWENGUINO_LCD_H_
#define DWENGUINO_LCD_H_


#include "dwenguinoBoard.h"
#include <avr/delay.h>
#include "dwenguinoAccelerometer.h"
//	Properties
#define LCD_WIDTH		16
#define LCD_HEIGHT		2
#define LCD_LASTLINE	(LCD_HEIGHT - 1)
#define LCD_LASTPOS		(LCD_WIDTH - 1)

//	Macro's
#define backlightOn()	(LCD_BACKLIGHT_ON)
#define backlightOff()	(LCD_BACKLIGHT_OFF)

#define appendStringToLCD(message)	appendStringToLCD_((const char*)(message))

//	Functions
void initLCD(void);
void clearLCD(void);

void commandLCD(const BYTE c);
void setCursorLCD(BYTE l, BYTE p);

void appendCharToLCD(const char c);
void printCharToLCD(const char s, BYTE l, BYTE p);

void appendIntToLCD(int i);
void printIntToLCD(int i, BYTE l, BYTE p);

void appendStringToLCD_(const char* message);
void appendStringToLCDcharptr(char* message);
/*!
* \brief Altered function. Didn't work properly before.
*\param message String to print.
*\param l Row.
*\param p Column.
*\return Void
*/
void printStringToLCD(char* message, BYTE l, BYTE p);
/*!
* \brief Added function. Similar to \a appendIntToLCD(int i)
*\param i Unsigned int to append.
*\return Void
*/
void appendUintToLCD(unsigned int i);
/*!
* \brief Added function. Similar to \a printIntToLCD(int i, BYTE l, BYTE p)
\param i Unsigned int to print.
\param l Row.
\param p Column.
*\return Void
*/
void printUintToLCD(unsigned int i, BYTE l, BYTE p);

/*!
* \brief Added function. Adds bit-strings to LCD RAM.
*\param c 5-bit bit-string, this is one line of a 8x5 character.
*\return Void
*/
void dataLCD(const BYTE c);

//	Structures
struct lcd_info_type{
	unsigned char line;
	unsigned char pos;
};

//	Keeps track of current line number and character position.
extern struct lcd_info_type lcd_info;

#endif /* DWENGUINO_LCD_H_ */
