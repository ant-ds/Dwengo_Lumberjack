/**
*\file dwenguinoLumberjack.c
*\author Antoine, Sebastiaan
*/

#include "../HeaderFiles/dwenguinoLumberjack.h"

Game* InitGame(){
	Game* game;
	game = (Game*)malloc(sizeof(Game));
	game->state = MENU;
	game->score = 0;
	game->side_jack = LEFT;
	game->counter = 0;
	game->difficulty = 100;
	game->tilt = 6;	
	game->speed = 0;
	game->tree = (int**)calloc(8,sizeof(int*));
	for (int i = 0; i < 8; i++) {
		game->tree[i] = (int*)calloc(2,sizeof(int));
	}
	return game;
}
void DeleteGame(Game* game){
	for (int i = 0; i < 8; i++) {
		free(game->tree[i]);
	}
	free(game->tree);
	free(game);
}

void UpdateTree(Game* game){
	int x = 0;
	if(game->counter == 4){	//check if a new branch has to be generated
		game->counter = -1;	
		switch(rand()%3){
			case 0:
				x = 2;
				break;
			default:
				x = 1;
				break;
			}
			switch (rand()%3) {
			case 0:
				game->tree[0][LEFT] = x;
				break;
			case 1:
				game->tree[0][RIGHT] = x;
				break;
		}
	}
	game->counter++;
  for(int i = 0; i < 8; i++){ //make branches descend
    for(int j = 0; j<2; j++){
      switch (game->tree[7-i][j]){
        case 0:
          break;
				default:
				if(game->counter == 0){
					game->tree[7-i+1][j] = game->tree[7-i][j];
					game->tree[7-i][j] = 0;
					break;
					}
        }
      }
    }
	}
void CheckGameOver(Game* game){
		if(game->state == DEAD || PORTA == 0){
				game->state = DEAD;
				for (int i = 0; i < 8; i++) { //clear tree array
					game->tree[i][1] = 0;
					game->tree[i][0] = 0;
				}
				PORTA = 0; //reset LEDs
		}
}

void CheckCollision(Game* game){
	if(game->counter == 4){
		if(game->tree[7][game->side_jack] == 1){
				game->state = DEAD;
		}
		else if(game->tree[7][game->side_jack] == 2){
				game->score -= 2;
				PORTA = PORTA >> 2;
		}
		else if(game->tree[7][!game->side_jack] == 1){
					game->score += 2;
		}
		else if(game->tree[7][!game->side_jack] == 2){
				game->score += 1;
				PORTA = (PORTA << 1)+1;
		}
	}
}
void UpdateTilt(Game* game){
	game->tilt = (int)(-readPitch()/17+5);
}
void UpdateSide(Game* game){
  	double x = readRoll();
  	if(x>PITCH_POINT){
  		game->side_jack = LEFT;
  	}
  	if(x<-PITCH_POINT){
  		game->side_jack = RIGHT;
  	}
  }

void setDifficulty(Game* game, int difficulty){
	game->difficulty = 6-difficulty;
}
