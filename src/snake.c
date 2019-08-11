#include "../include/snake.h"

bool GameOver ;
int x , y ;
const int BoxWidth = 120 , BoxHeight = 30 ;
int score ;
int food_X , food_Y ;
enum Directions { STOP = 0 , LEFT , RIGHT , UP , DOWN};
enum Directions dir;
int Xtail[TAIL] , Ytail[TAIL];
int ntail= 0 ;

void Start(){
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    
    GameOver = false;
    dir = STOP;
    x = BoxWidth / 2 ;
    y = BoxHeight / 2;
    food_X = (rand() % BoxWidth)  + 2 ;
    food_Y = (rand() % BoxHeight) + 2 ;
    score = 0;
}


void DrawSnake(){
    start_color();
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    clear();
    
    for(int i = 0 ; i < BoxHeight + 2 ; i++){
        for (int j = 0 ; j < BoxWidth + 2 ; j++){
            if (i == 0 || i == (BoxHeight+1)){
                if (j % 2 == 0){
                    attron(COLOR_PAIR(1));
                    mvprintw(i,j,"*");
                    attroff(COLOR_PAIR(1));
                }
                else {
                    attron(COLOR_PAIR(5));
                    attron(A_BLINK);
                    mvprintw(i,j,"*");
                    attroff(A_BLINK);
                    attroff(COLOR_PAIR(5));
                }    
            }
            else if (j == 0 || j== BoxWidth + 1 ){
                if ( i % 2 == 0){
                    attron(COLOR_PAIR(1));
                    mvprintw(i,j,"*");
                    attroff(COLOR_PAIR(1));
                }
                else {
                    attron(COLOR_PAIR(5));
                    attron(A_BLINK);
                    mvprintw(i,j,"*");
                    attroff(A_BLINK);
                    attroff(COLOR_PAIR(5));
                    
                }
            }
            else if (i == y && j == x)
                mvprintw(i,j,"O");
            
            else if (i == food_Y && j == food_X){
                attron(COLOR_PAIR(4));
                mvprintw(i,j,"@");
                attroff(COLOR_PAIR(4));
            }
            else{ 
                for (int k = 0 ; k < ntail ;k++){
                    if (Xtail[k] == j && Ytail[k] == i)
                        mvprintw(i,j,"o");
                }
            }       
        }
    }
    
    attron(A_BLINK);
    
    for (int i = 0 ; i < BoxWidth / 2 - 3 ; i++){
        if (i % 2 == 0 ){        
            attron(COLOR_PAIR(3));
            mvprintw(BoxHeight + 5,i ,"*");
            attroff(COLOR_PAIR(3));
        }
        else {
            attron(COLOR_PAIR(4));
            mvprintw(BoxHeight + 5,i ,"*");
            attroff(COLOR_PAIR(4));
        }
        
    }
    for (int i = (BoxWidth / 2) + 6 ; i < BoxWidth + 2 ; i++){
        if (i % 2 ==0 ){        
            attron(COLOR_PAIR(3));
            mvprintw(BoxHeight + 5,i ,"*");
            attroff(COLOR_PAIR(3));
        }
        else {
            attron(COLOR_PAIR(4));
            mvprintw(BoxHeight + 5,i ,"*");
            attroff(COLOR_PAIR(4));
        }
        
    }   
    attron(COLOR_PAIR(2));
    mvprintw(BoxHeight + 5,(BoxWidth / 2) - 2 ,"SCORE %d",score);
    attroff(COLOR_PAIR(2));
    attroff(A_BLINK);
    refresh();
}


void UserInput(){
    keypad(stdscr, TRUE);
    halfdelay(1);
    int ch = getch();
    switch (ch) {
        case KEY_LEFT:
            dir = LEFT;
            break;        
        case KEY_RIGHT:
            dir = RIGHT;
            break;
        case KEY_DOWN:
            dir = DOWN;
            break;
        case KEY_UP:
            dir = UP;
            break;
        case 113:
            GameOver = true;
            break;
    }
}


void Rules(){
    
    Xtail[0] = x;
    Ytail[0] = y;
    int PrevX = Xtail[0];
    int PrevY = Ytail[0];
    int Prev2x , Prev2y;
    Xtail[0] = x;
    Ytail[0] = y;
    
    for (int i = 0 ; i < ntail ; i++){
        Prev2x = Xtail[i];
        Prev2y= Ytail[i];
        Xtail[i] =PrevX ;
        Ytail[i] =PrevY ;
        PrevX = Prev2x  ;
        PrevY = Prev2y  ;
    }
    
    switch (dir){
        case LEFT :
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP :
            y--;
            break;
        case DOWN:
            y++;
            break;
        default :
            break;
    }
    
    if ( x > BoxWidth || y > BoxHeight || x < 1 || y < 1)
        GameOver = true;
    
    if (x==food_X && y==food_Y){
        score++;
        food_X = (rand() % BoxWidth)  + 2 ;
        food_Y = (rand() % BoxHeight) + 2 ;        
        ntail++;
    }
    
    for (int i = 0 ; i < ntail ; i++){
        if (Xtail[i] == x && Ytail[i] == y)
            GameOver = true;
    }
    
}


int main(){
    Start();    
    while(!GameOver){
        DrawSnake();
        UserInput();
        Rules();
    }   
    getch();
    endwin();
}
