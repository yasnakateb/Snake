CC = gcc
LIBS  = -lncurses 
SRC = src/snake.c
INCLUDE = include/

run: snake
	./snake

snake: 
	$(CC) $(SRC) -I $(INCLUDE) $(LIBS) -o $@ 

