/**
*\file dwenguinoLumberjack.h
*\brief This file contains all the functions that are made specifically for the game.
*
*Almost all changes happen by changing the variables in the \a Game struct.
*\author Antoine, Sebastiaan
*/


#ifndef DWENGUINO_LUMBERJACK_H
#define DWENGUINO_LUMBERJACK_H

#include <stdlib.h>
#include "dwenguinoAccelerometer.h"

#define PITCH_POINT 10
#define MENU 0
#define ALIVE 1
#define DEAD 2
/*!
* \brief Struct containing all game variables.
*/
struct Game {
	/**
	\brief Array containing the approximate positions of the branches in the tree.

	This variable is a 2D array consisting of two 1D arrays of length 8: they represent the left side and the right side of the tree.\n
	These arrays are used to store the approximate positions of the branches in the tree. One element in the array contains 5 positions in the tree.\n
	There can only be one branch in the total of the 5 positions. The exact position is stored in \a counter .
	*/
	int** tree;
	int side_jack; /**<\brief Keeps track of the side of the player (left or right). */
	int score; /**<\brief Keeps track of the score. */
	int counter; /**<\brief Gives the exact position of the branch (1 to 5).*/
	int difficulty; /**<\brief Defines the rate at which an LED goes off. */
	int state; /**<\brief Gives the game state: ALIVE, DEAD or MENU*/
	int tilt; /**<\brief Determines the speed at which the branches fall down*/
	int speed; /**<\brief Rolling counter of the game. \detailed Caps at 29999, after that it goes back to 0 to prevent overflow.*/
};

typedef struct Game Game;

/*!
* \brief Allocates space to the \a Game struct and the tree array and assigns the right values to the variables of the \a Game struct.
*
* This function needs to be called before using any of the functions in this file.
*\return Pointer to the address of the \a Game struct.
*/
Game* InitGame();

/*!
* \brief Frees up the space allocated to the game.
*\param game Pointer to the \a Game struct.
*\return Void
*/
void DeleteGame(Game* game);

/*!
* \brief Updates the branches of the tree.
*
* This function generates new branches at the right time and updates the existing branches to fall one position.
*\param game Pointer to the \a Game struct.
*\return Void
*/
void UpdateTree(Game* game);

/*!
* \brief Updates the side on which Jack is standing, depending on the roll angle of the accelerometer.
*\param game Pointer to the \a Game struct.
*\return Void
*/
void UpdateSide(Game* game);

/*!
* \brief Changes the \a tilt variable depending on the pitch of the accelerometer
*\param game Pointer to the \a Game struct.
*\return Void
*/
void UpdateTilt(Game* game);

/*!
* \brief Sets the \a difficulty of the game.
*\param game Pointer to the \a Game struct.
*\param difficulty New difficulty to be set.
*\return Void
*/
void setDifficulty(Game* game, int difficulty);

/*!
* \brief Verifies if a branch is colliding with Jack and changes the game \a state and LEDs accordingly.
*\param game Pointer to the \a Game struct.
*\return Void
*/
void CheckCollision(Game* game);

/*!
* \brief Verifies the state of the LEDs and the \a state of the game for a "Game Over" and changes the \a Game struct accordingly.
*\return Void
*
*In case of a "Game-Over", the tree array is emptied, the LEDs are all turned off and game state is set to \a DEAD.
*\param game Pointer to the \a Game struct.
*\return Void
*/
void CheckGameOver(Game* game);

#endif //DWENGUINO_LUMBERJACK_H
