/**
*\file dwenguinoPrint.c
*\author Antoine, Sebastiaan
*/

#include "../HeaderFiles/dwenguinoPrint.h"

void generateLumberjack(Game* game){
	commandLCD(0x40);
	if(game->side_jack == LEFT){
    //Jack_L_bottom characters
	if(game->counter < 2){
			dataLCD(0b11111);
	    dataLCD(0b00000);
	    dataLCD(0b00000);
			dataLCD(0b11000);
	    dataLCD(0b11111);
	    dataLCD(0b11100);
	    dataLCD(0b11111);
	    dataLCD(0b10000);
	    //Jack_L_top;
			dataLCD(0b11111);
	    dataLCD(0b00000);
			dataLCD(0b00100);
	    dataLCD(0b00111);
	    dataLCD(0b00011);
	    dataLCD(0b00011);
	    dataLCD(0b00011);
	    dataLCD(0b00000);
		}
		else
		{
		  dataLCD(0b11111);
		  dataLCD(0b00000);
		  dataLCD(0b11000);
		  dataLCD(0b10000);
		  dataLCD(0b11111);
		  dataLCD(0b11100);
		  dataLCD(0b11111);
		  dataLCD(0b10000);
		  //Jack_L_top characters
		  dataLCD(0b00000);
	      dataLCD(0b00100);
	      dataLCD(0b00111);
	      dataLCD(0b00000);
	      dataLCD(0b00011);
	      dataLCD(0b00011);
	      dataLCD(0b00011);
	      dataLCD(0b00000);
		}
		//Left tree character
		dataLCD(0b00000);
	  dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b11111);
		//Right tree character
		dataLCD(0b11111);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
  	}
		else{
			if(game->counter < 2){
			  //Jack_R_bottom character
			  dataLCD(0b10000);
			  dataLCD(0b11111);
			  dataLCD(0b11100);
			  dataLCD(0b11111);
			  dataLCD(0b11000);
			  dataLCD(0b00000);
			  dataLCD(0b00000);
			  dataLCD(0b11111);
			  //Jack_R_top character
			  dataLCD(0b00000);
			  dataLCD(0b00011);
			  dataLCD(0b00011);
			  dataLCD(0b00011);
			  dataLCD(0b00111);
			  dataLCD(0b00100);
			  dataLCD(0b00000);
			  dataLCD(0b11111);
			}
			else
			{
			  //Jack_R_bottom character
			  dataLCD(0b10000);
			  dataLCD(0b11111);
			  dataLCD(0b11100);
			  dataLCD(0b11111);
			  dataLCD(0b10000);
			  dataLCD(0b11000);
			  dataLCD(0b00000);
			  dataLCD(0b11111);
			  //Jack_R_top character
			  dataLCD(0b00000);
			  dataLCD(0b00011);
			  dataLCD(0b00011);
			  dataLCD(0b00011);
			  dataLCD(0b00000);
			  dataLCD(0b00111);
			  dataLCD(0b00100);
			  dataLCD(0b00000);
			}
	//Left tree character
	dataLCD(0b00000);
    dataLCD(0b00000);
    dataLCD(0b00000);
    dataLCD(0b00000);
    dataLCD(0b00000);
    dataLCD(0b00000);
    dataLCD(0b00000);
    dataLCD(0b11111);
    //Right tree character
    dataLCD(0b11111);
    dataLCD(0b00000);
    dataLCD(0b00000);
    dataLCD(0b00000);
    dataLCD(0b00000);
    dataLCD(0b00000);
    dataLCD(0b00000);
    dataLCD(0b00000);

	}

}

void generateBranch(Game* game){
	switch(game->counter){
		case 0:
		//Right branch character
		for(int k = 0; k < 7; k++){
			dataLCD(0b10000);
		}
		dataLCD(0b11111);
		//Left branch character
		dataLCD(0b11111);
		for(int k = 0; k < 7; k++){
			dataLCD(0b10000);
		}
		break;
		case 1:
		//Right branch character
		for(int k = 0; k < 7; k++){
			dataLCD(0b01000);
		}
		dataLCD(0b11111);
		//Left branch character
		dataLCD(0b11111);
		for(int k = 0; k < 7; k++){
			dataLCD(0b01000);
		}
		break;
		case 2:
		//Right branch character
		for(int k = 0; k < 7; k++){
			dataLCD(0b00100);
		}
		dataLCD(0b11111);
		//Left branch character
		dataLCD(0b11111);
		for(int k = 0; k < 7; k++){
			dataLCD(0b00100);
		}
		break;
		case 3:
		//Right branch character
		for(int k = 0; k < 7; k++){
			dataLCD(0b00010);
		}
		dataLCD(0b11111);
		//Left branch character
		dataLCD(0b11111);
		for(int k = 0; k < 7; k++){
			dataLCD(0b00010);
		}
		break;
		case 4:
		//Right branch character
		for(int k = 0; k < 7; k++){
			dataLCD(0b00001);
		}
		dataLCD(0b11111);
		//Left branch character
		dataLCD(0b11111);
		for(int k = 0; k < 7; k++){
			dataLCD(0b00001);
		}
		break;
	}
}

void generateSmallBranch(Game* game){
	switch(game->counter){
		case 0:
		//Right small branch character
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b10000);
		dataLCD(0b10000);
		dataLCD(0b10000);
		dataLCD(0b10000);
		dataLCD(0b11111);
		//Left small branch character
		dataLCD(0b11111);
		dataLCD(0b10000);
		dataLCD(0b10000);
		dataLCD(0b10000);
		dataLCD(0b10000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		break;
		case 1:
		//Right small branch character
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b01000);
		dataLCD(0b01000);
		dataLCD(0b01000);
		dataLCD(0b01000);
		dataLCD(0b11111);
		//Left small branch character
		dataLCD(0b11111);
		dataLCD(0b01000);
		dataLCD(0b01000);
		dataLCD(0b01000);
		dataLCD(0b01000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		break;
		case 2:
		//Right small branch character
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00100);
		dataLCD(0b00100);
		dataLCD(0b00100);
		dataLCD(0b00100);
		dataLCD(0b11111);
		//Left small branch character
		dataLCD(0b11111);
		dataLCD(0b00100);
		dataLCD(0b00100);
		dataLCD(0b00100);
		dataLCD(0b00100);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		break;
		case 3:
		//Right small branch character
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00010);
		dataLCD(0b00010);
		dataLCD(0b00010);
		dataLCD(0b00010);
		dataLCD(0b11111);
		//Left small branch character
		dataLCD(0b11111);
		dataLCD(0b00010);
		dataLCD(0b00010);
		dataLCD(0b00010);
		dataLCD(0b00010);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		break;
		case 4:
		//Right small branch character
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00001);
		dataLCD(0b00001);
		dataLCD(0b00001);
		dataLCD(0b00001);
		dataLCD(0b11111);
		//Left small branch character
		dataLCD(0b11111);
		dataLCD(0b00001);
		dataLCD(0b00001);
		dataLCD(0b00001);
		dataLCD(0b00001);
		dataLCD(0b00000);
		dataLCD(0b00000);
		dataLCD(0b00000);
		break;
	}
}




void printGameToLCD(Game* game){
	generateLumberjack(game);
	generateBranch(game);
	generateSmallBranch(game);
	//print Jack on LCD
	printCharToLCD(Jack_bottom,game->side_jack,15);
	printCharToLCD(Jack_top,game->side_jack,14);
	//print other side than Jack on LCD
	printCharToLCD((game->side_jack+1)%2+2,(game->side_jack-1)%2,15);
	if(game->counter < 2){
		printCharToLCD((game->side_jack+1)%2+2,(game->side_jack-1)%2,14);
	}
	//print treetop on LCD
	printStringToLCD("###", 1, 3);
	printStringToLCD("###", 0, 3);

	//print tree branches
	for(int i = 0; i < 8; i++){
		for(int j = 0; j<2; j++){
			switch(game->tree[i][j]){
				case 0:
				printCharToLCD(2+j, j, i+6);
				break;
				case 1:
				printCharToLCD(4+j, j, i+6);
				break;
				case 2:
				printCharToLCD(6+j, j, i+6);
			}
		}
	}
}

void printGameOver(Game* game){
	printStringToLCD("***GAME OVER***", 0, 0);
	printStringToLCD("Score: ", 1, 3);
	appendIntToLCD(game->score);

}

void printMenu(Game*game, int difficulty){
	printStringToLCD("****READY ?****", 0, 0);
	printStringToLCD("Difficulty: ", 1, 0);
	printIntToLCD(difficulty, 1, 13);
}
