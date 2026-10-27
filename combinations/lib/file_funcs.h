#ifndef FILE_FUNCS_H
#define FILE_FUNCS_H

#include <stdio.h>

/*
 * find_index
 * Searches a file for words seperated by a given deliminator and 
 * adds the index of the start of each word to an array
 *
 * :: FILE *file       :: file pointer to search
 * :: int index_arr[]  :: array to add found indexes to
 * :: char deliminator :: the character seperating different words
 *
 * Returns the total count of words
 */
int find_index(FILE *file, int index_arr[], char deliminator);

/*
 * birdify
 * Writes a bird permutation to a given file based on an int array 
 *
 * :: int target[]      :: int array of pattern
 * :: int size          :: length of target[]
 * :: FILE *file_in     :: File pointer to read file
 * :: FILE *file_out    :: File pointer to write file
 * :: int bird_idexes[] :: The starting index of each bird in the read file
 *
 */
void birdify(int target[], int size, FILE *file_in, 
	             FILE *file_out, int bird_indexes[]);

#endif