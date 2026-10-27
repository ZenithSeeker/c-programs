#include "file_funcs.h"

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
void birdify(int target[], int size, FILE *file_in, FILE *file_out,
             int bird_indexes[]) {
    char c;
    for (int i = 0; i < size; i++) {
        fseek(file_in, bird_indexes[target[i]], SEEK_SET);

        while (((c = fgetc(file_in)) != EOF) && (c != ' ') && (c != '\n')) {
            fputc(c, file_out);
        }
        (i == size - 1) || fputc(' ', file_out);
    }
    fputc('\n', file_out);
}


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
int find_index(FILE *file, int index_arr[], char deliminator) {
    int file_pos = 0;
    int i = 0;
    int prev_space = 1;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n' || c == deliminator) {
            prev_space = 1;
        } else {
            if (prev_space) {
                index_arr[i] = file_pos;
                i++;
            }
            prev_space = 0;
        }
        file_pos++;
    }
    return i;
}


