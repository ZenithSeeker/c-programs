#include "parse_arg.h"

#define INVALID_VALUE -1

/*
parse_arg
    Inteprets command line args 
    :: int argc :: Amount of arguments 
    :: char** argv :: Array of arguments
    Returns a settings struct containing the user's choices.
*/
struct settings parse_arg(int argc, char ** argv) {
    struct settings cl_values;
    cl_values.wrap = 0;
    cl_values.total = INVALID_VALUE;
    cl_values.upper = INVALID_VALUE;
    cl_values.lower = INVALID_VALUE;
    cl_values.step = INVALID_VALUE;
    cl_values.board_raw = NULL;

    int first_letter;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == '-') {
                first_letter = argv[i][2];
            } 
            else {
                first_letter = argv[i][1];
            }
            if (first_letter == 'w') {
                cl_values.wrap = 1;
            } 
            else {
                int value = atoi(&(argv[i][get_index(argv[i],'=') + 1]));

                if (first_letter == 't')
                {
                    cl_values.total = value;
                }
                else if (first_letter == 'l')
                {
                    cl_values.lower = value;
                }
                else if (first_letter == 'u')
                {
                    cl_values.upper = value;
                }
                else if (first_letter == 's')
                {
                    cl_values.step = value;
                }
            }   
        } 
        else {
            cl_values.board_raw = argv[i];
        }

    }

    error_check(cl_values);

    return cl_values;
}

/*
error_check
    Checks if chosen values are valid
    :: struct settings chosen_values :: Array of choices to check
    If invalid, warns user and exits the program.
*/
int error_check(struct settings chosen_values)
{
    if (0 > chosen_values.total)
    {
        printf("Must provide a non-negative integer for total.\n");
        exit(1);
    }
    else if (0 >= chosen_values.step)
    {
        printf("Must provide a positive integer for step.\n");
        exit(1);
    }
    else if (0 > chosen_values.lower)
    {
        printf("Must provide a non-negative integer for lower.\n");
        exit(1);
    }
    else if ((8 < chosen_values.upper) || (INVALID_VALUE == chosen_values.upper))
    {
        printf("Must provide an integer no larger than 8 for upper.\n");
        exit(1);
    }
    else if (chosen_values.lower > chosen_values.upper)
    {
        printf("lower must be no larger than upper.\n");
        exit(1);
    }
    else if (chosen_values.board_raw == NULL)
    {
        printf("Must provide a board, e.g. 000/111/000.\n");
        exit(1);
    }
    else if (!is_valid_board(chosen_values.board_raw))
    {
        printf("Board must contain only 0, 1 and /.\n");
        exit(1);
    }
    else if (!is_rectangle(chosen_values.board_raw))
    {
        printf("Board must be a rectangle.\n");
        exit(1);
    }
    else if (!fits_board(chosen_values.board_raw))
    {
        printf("Board can be at most %d x %d.\n", MAX_BOARD_WIDTH, MAX_BOARD_HEIGHT);
        exit(1);
    }
    return 0;
}

/*
get_index
    Scans str for a char and returns index 
    :: char* str :: String to search in 
    :: char target :: target character
    Returns index of first appearance (-1 for no appearance).
*/
int get_index(char* str, char target){
    int i = 0;
    int return_value = -1;

    while (str[i] != '\0') {
        if (str[i] == target) {
            return_value = i;
            break;
        }
        else {
            i++;
        }     
    }
    return return_value;
}

/*
is_rectangle
    Checks if string given by user is a rectangle 
    :: char* board_raw :: String to be checked
    Returns result
*/
int is_rectangle(char* board_raw) {
    int is_rectangle = 1;
    char* remaining_str = board_raw;
    int first_row_len = get_index(board_raw, '/');
    int next_row_len = first_row_len;

    while (next_row_len != -1) {
        if (next_row_len != first_row_len)
        {
            is_rectangle = 0;
            break;
        }
        
        remaining_str += sizeof(char) * (next_row_len + 1);
        next_row_len = get_index(remaining_str, '/');

    }     

    // the final row has no trailing '/', so compare its length separately
    if (is_rectangle && first_row_len != -1 && (int)strlen(remaining_str) != first_row_len) {
        is_rectangle = 0;
    }

    return is_rectangle;
}

/*
is_valid_board
    Checks the board only contains cells (0 or 1) and row separators
    :: char* board_raw :: String to be checked
    Returns result
*/
int is_valid_board(char* board_raw) {
    for (int i = 0; board_raw[i] != '\0'; i++) {
        if (board_raw[i] != '0' && board_raw[i] != '1' && board_raw[i] != '/') {
            return 0;
        }
    }
    return board_raw[0] != '\0';
}

/*
fits_board
    Checks the board fits in the fixed-size state array
    :: char* board_raw :: String to be checked (already known to be a rectangle)
    Returns result
*/
int fits_board(char* board_raw) {
    int width = get_index(board_raw, '/');
    int height = 1;
    for (int i = 0; board_raw[i] != '\0'; i++) {
        height += (board_raw[i] == '/');
    }
    if (width == -1) {
        width = strlen(board_raw);
    }
    return (width <= MAX_BOARD_WIDTH) && (height <= MAX_BOARD_HEIGHT);
}







