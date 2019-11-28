/**
*\file dwenguinoPrint.h
*\author Antoine, Sebastiaan
*\brief This file contains all the functions that generate characters and print them on the LCD.
*/

#ifndef DWENGUINO_PRINT_H


#include "dwenguinoAccelerometer.h"
#include "dwenguinoLCD.h"

#define Jack_bottom 0
#define Jack_top 1
#define EMPTY_BRANCH_L 2
#define EMPTY_BRANCH_R 3
#define Branch_L 4
#define Branch_R 5


/*!
* \brief Puts the right Jack characters in the LCD RAM.
*
* The jack characters depends on the game \a state and the \a counter for the animation.
*\param game Pointer to the \a Game struct.
*\return Void
*/
void generateLumberjack(Game* game);

/*!
* \brief Puts the right branch characters in the LCD RAM.
*
* The right branch character depends on the game \a counter.
*\param game Pointer to the \a Game struct.
*\return Void
*/
void generateBranch(Game* game);

/*!
* \brief Puts the right small branch characters in the LCD RAM.
*
* The right small branch character depends on the \a counter variable.
*\param game Pointer to the \a Game struct.
*\return Void
*/
void generateSmallBranch(Game* game);

/*!
* \brief Prints the tree together with Jack to the LCD
*
* This function is heavily dependent on the characters created in the \a generate functions.
*\param game Pointer to the \a Game struct.
*\return Void
*/
void printGameToLCD(Game* game);

/*!
* \brief Prints "Game Over" screen
*
* The "Game Over" screen contains the game \a score.
*\param game Pointer to the \a Game struct.
*\return Void
*/
void printGameOver(Game* game);

/*!
* \brief Prints "Menu" screen
*\param game Pointer to the \a Game struct.
*\param difficulty The difficulty to print on screen.
*\return Void
*/
void printMenu(Game* game, int difficulty);
#endif
