CC = gcc
LIBS  = -lncurses 
SRC = src/snake.c
INCLUDE = include/snake.h

run: snake
	./snake

snake: 
	$(CC) $(SRC) -I $(INCLUDE) $(LIBS) -o $@ 

