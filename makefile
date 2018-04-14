# Make files
#
# Written by Brodey R. Dickerson
#
# last-modified: Thu Feb 15 01:34:00 2018

# Next line tells Make to use the gnu compiler
CC = g++

# Next line says what options to use to compile programs
OPTIONS=-Wall

# This pattern compilers the executable and archives the source code
all: build archive

# This pattern compiles the finale executable
build: Game

# This pattern compiles the final executable
Game: main.o othello.o game.o
	$(CC) $(OPTIONS) main.o game.o othello.o -o Game

# This pattern compiles the object code for main.
main.o: colors.h game.h othello.h main.cc
	$(CC) -c $(OPTIONS) main.cc

# This pattern compiles the object code for game.
game.o: game.h game.cc
	$(CC) -c $(OPTIONS) game.cc

# This pattern compiles the object code for othello.
othello.o: colors.h game.h space.h othello.h othello.cc
	$(CC) -c $(OPTIONS) othello.cc


# This pattern gets rid of all the .o files, the executable, and any
# emacs files left around.
clean:
	rm -f Game othello.o main.o game.o *~


#This pattern archives all the files
archive: main.cc game.cc othello.cc colors.h game.h space.h othello.h 2401fal17proj6.doc EXPLANATION.txt OthelloRules.pdf makefile
	tar -cvf BD948215_Archive.tar main.cc game.cc othello.cc colors.h 	game.h space.h othello.h 2401fal17proj6.doc EXPLANATION.txt OthelloRules.pdf makefile
