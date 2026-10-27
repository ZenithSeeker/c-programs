#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

/*
make_board
    Takes the string given by user and creates a 10 * 10 array.
    :: char* board_raw :: The string the board is constructed with.
    Returns a board_struct struct that contains the array.
*/
struct board_struct make_board(char* board_raw);

/*
update_board
    Runs a single iteration of the game of life on the given board.
    :: struct board_struct board :: The struct containing the
        board to be modified.
    :: struct settings chosen :: Struct containing parameters for
        the game.
    Returns a board_struct struct that contains the array.
*/
struct board_struct update_board(struct board_struct board,
                                 struct settings chosen);

/*
print_board_struct
    Prints the state of given board_struct structure
    :: struct board_struct board :: Structure containing board
        to be printed.
*/
void print_board_struct(struct board_struct board);

/*
copy_board
    Copies the values from one array to another
    :: int copy[MAX_BOARD_HEIGHT][MAX_BOARD_WIDTH] :: int array to copy values
        to
    :: struct board_struct original :: structure containing original array
*/
void copy_board(struct board_struct original,
                int copy[MAX_BOARD_HEIGHT][MAX_BOARD_WIDTH]);

#endif

