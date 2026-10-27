#ifndef PARSE_ARG_H
#define PARSE_ARG_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

/*
parse_arg
    Inteprets command line args 
    :: int argc :: Amount of arguments 
    :: char** argv :: Array of arguments
    Returns a settings struct containing the user's choices.
*/
struct settings parse_arg(int argc, char** argv);

/*
error_check
    Checks if chosen values are valid
    :: struct settings chosen_values :: Array of choices to check
    If invalid, warns user and exits the program.
*/
int error_check(struct settings chosen_values);

/*
is_rectangle
    Checks if string given by user is a rectangle 
    :: char* board_raw :: String to be checked
    Returns result
*/
int is_rectangle(char* board_raw);

/*
get_index
    Scans str for a char and returns index 
    :: char* str :: String to search in 
    :: char target :: target character
    Returns index of first appearance (-1 for no appearance).
*/
int get_index(char* str, char target);

/*
is_valid_board
    Checks the board only contains cells (0 or 1) and row separators
    :: char* board_raw :: String to be checked
    Returns result
*/
int is_valid_board(char* board_raw);

/*
fits_board
    Checks the board fits in the fixed-size state array
    :: char* board_raw :: String to be checked
    Returns result
*/
int fits_board(char* board_raw);

#endif
