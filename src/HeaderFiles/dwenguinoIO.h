/**
*\file dwenguinoIO.h
*\author Antoine, Sebastiaan
*\brief This file contains the initialization procedures for the buttons and the LEDs.
*/
#ifndef DWENGUINO_IO_H
#define DWENGUINO_IO_H
#include <avr/io.h>
#include "dwenguinoLumberjack.h"

/*!
* \brief Initializes the LEDs by setting the registers right.
*\return Void
*/
void initLED();
/*!
* \brief Initializes the buttons by setting the registers right.
*\return Void
*/
void initButtons();
#endif
