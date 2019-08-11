#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#define TAIL 100


bool GameOver ;
int x , y ;
const int BoxWidth = 120 , BoxHeight = 30 ;
int score ;
int food_X , food_Y ;
enum Directions { STOP = 0 , LEFT , RIGHT , UP , DOWN};
enum Directions dir;
int Xtail[TAIL] , Ytail[TAIL];
int ntail= 0 ;

void Start();
void DrawSnake();
void UserInput();
void Rules();
