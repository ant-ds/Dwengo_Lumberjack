/*!
 * \file dwenguinoAccelerometer.h
 * \author Antoine, Sebastiaan
 * \brief This file contains all the functions that interact with the accelerometer. 
 */
#ifndef DWENGUINO_ACCELEROMETER_H
#define DWENGUINO_ACCELEROMETER_H


#define LEFT 1
#define RIGHT 0



#include "dwenguinoLCD.h"
#include "dwenguinoLumberjack.h"

 /*!
 * \brief Error function that is called on when initialization of the accelerometer fails. Prints an error to the LCD screen.
 *
 * This error serves only as a warning and doesn't exit the program. The player has to manually press the reset button.
 *\return Void
 */
void error();

/*!
* \brief Initializes the data-transfer between Dwenguino and accelerometer following the Master/Slave protocol.
* 
* If the initialization fails (probably due to faulty hardware), the \a error function is called.
*\return Void
*/
void initAccelerometer();

/*!
*\brief Reads data from a specified register of the accelerometer following the Master/Slave protocol
*\param reg Register to read.
*\return Register data.
*/
int read(int reg);

/*!
* \brief Reads the two registers containing data about the x-axis values and combines them.
*
* The register containing the most 8 significant bits of x is 0x3B, the one containing the 8 less significant bits is 0x3C.
*\return X-axis accelerometer data.
*/
int readX();

/*!
* \brief Reads the two registers containing data about the y-axis values and combines them.
*
* The register containing the most 8 significant bits of y is 0x3D, the one containing the 8 less significant bits is 0x3E.
*\return Y-axis accelerometer data.
*/
int readY();

/*!
* \brief Reads the two registers containing data about the z-axis values and combines them.
*
* The register containing the most 8 significant bits of z is 0x3F, the one containing the 8 less significant bits is 0x40.
*\return Z-axis accelerometer data.
*/
int readZ();

/*!
* \brief Uses the other read-functions to calculate the pitch angle at which the accelerometer is turned.
*
* The formula for the pitch (in radians) is: \f$ Pitch = atan\left(\frac{-X}{Z}\right) \f$
*
* \a X is the value returned in \a readX(),
* \a Z is the value returned in \a readZ()
*\return Pitch angle in degrees.
*/
int readPitch();
/*!
* \brief Uses the other read-functions to calculate the roll angle at which the accelerometer is turned.
*
* The formula for the roll (in radians) is: \f$ Roll = atan\left(\frac{Y}{Z}\right) \f$
*
* \a Y is the value returned in \a readY(),
* \a Z is the value returned in \a readZ()
*\return Roll angle in degrees.
*/
int readRoll();
 #endif //DWENGUINO_ACCELEROMETER_H
