#ifndef ARG_PARSE_H
#define ARG_PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define MAX_ARR_LENGTH 32

struct settings {
	int hole_num;
	int order_matters;
	int is_replacement;
	char* file_in;
	char* file_out;
};

/*
 * arg_parse
 * Parses args and returns a settings struct containing the user's choices
 *
 * :: int argc    :: count of arguments
 * :: char *argv[]      :: array of argument strings
 *
 * Returns the struct settings
 */
struct settings arg_parse(int argc, char *argv[]);

#endif