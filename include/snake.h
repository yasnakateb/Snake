#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#define TAIL 100


extern bool GameOver;
extern int x , y;
const int BoxWidth, BoxHeight;
extern int score;
extern int food_X , food_Y;
extern int Xtail[TAIL] , Ytail[TAIL];
extern int ntail;

void Start();
void DrawSnake();
void UserInput();
void Rules();
