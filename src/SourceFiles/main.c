/**
*\file main.c
*\author Antoine, Sebastiaan
*\brief Enables button interrupts and ties everything together for the game to work as intended.
*/

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <math.h>
#include "HeaderFiles/dwenguinoBoard.h"
#include "HeaderFiles/dwenguinoLCD.h"
#include "HeaderFiles/dwenguinoAccelerometer.h"
#include "HeaderFiles/dwenguinoPrint.h"
#include "HeaderFiles/dwenguinoLumberjack.h"
#include "HeaderFiles/dwenguinoIO.h"

int status = MENU;
int difficulty = 1;
int buttonwait = 0;
/*!
* \brief Interrupt function for the west button. Decreases the difficulty.
*/
ISR(INT4_vect){
  if(!buttonwait){
    buttonwait = 1;
    if(difficulty != 1){
      difficulty--;
    }
  }
}

/*!
* \brief Interrupt function for the south button. Starts the game.
*/
ISR(INT5_vect){
  if(!buttonwait){
    buttonwait = 1;
    status = ALIVE;
  }
}

/*!
* \brief Interrupt function for the east button. Increases the difficulty.
*/
ISR(INT6_vect){
  if(!buttonwait){
    buttonwait = 1;
    if(difficulty != 5){
      difficulty++;
    }
  }
}

/*!
* \brief Initializes everything and starts the game-loop.
* \return Should not return.
*/
int main(){
  srand(readPitch()); //provides another random seed every time the game is played, so the tree changes every game.
  initBoard();
  initLCD();
  backlightOn();
  initAccelerometer();
  Game* game = InitGame();
  initLED();
  initButtons();
  while(1){
    while (game->state == MENU) {
      setDifficulty(game, difficulty);
      printMenu(game, difficulty);
      _delay_ms(400);
      buttonwait = 0;
      clearLCD();
      if(status == ALIVE){
        game->state = ALIVE;
      }
    }

    while (game->state == ALIVE) {
      UpdateSide(game);  //set Jacks position right.
      if(game->speed % game->tilt == 0){ //make branches fall and run the corresponding updates and checks. 
        UpdateTilt(game);
        CheckCollision(game);
        CheckGameOver(game);
        UpdateTree(game);
      }
      if(game->speed % (game->difficulty*game->difficulty*30) == 0){ //LED turning off at interval time depending on difficulty
        PORTA = PORTA >> 1;
      }


      printGameToLCD(game);
      _delay_ms(40);
      clearLCD();
      game->speed = (game->speed + 1)%30000;
    }

	while(game->state == DEAD){
      printGameOver(game);
    }
}
DeleteGame(game);
}
