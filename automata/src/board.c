#include "board.h"


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
                                 struct settings chosen) {
    int previous[MAX_BOARD_HEIGHT][MAX_BOARD_WIDTH];
    copy_board(board, previous);

    int h = board.height;
    int w = board.width;

    //iterate over each cell
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            //iterates over neighbours of each cell and sums value
            int neighbour_sum = 0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    int value = previous[(y + i + h) % h][(x + j + w) % w];
                    int in_bounds =
                        ((0 <= (y + i)) && ((y + i) < board.height) &&
                         (0 <= (x + j)) && ((x + j) < board.width));
                    neighbour_sum += value * ((in_bounds) || (chosen.wrap));
                }
            }
            //Removes itself from total and updates value
            neighbour_sum -= previous[y][x];
            board.state[y][x] = ((chosen.lower <= neighbour_sum) &&
                                 (chosen.upper >= neighbour_sum));
        }
    }

    return board;
}


/*
copy_board
    Copies the values from one array to another
    :: int copy[MAX_BOARD_HEIGHT][MAX_BOARD_WIDTH] :: int array to copy values
        to
    :: struct board_struct original :: structure containing original array
*/
void copy_board(struct board_struct original, int copy[MAX_BOARD_HEIGHT][MAX_BOARD_WIDTH]) {
    for (int y = 0; y < MAX_BOARD_HEIGHT; y++) {
        for (int x = 0; x < MAX_BOARD_WIDTH; x++) {
            copy[y][x] = original.state[y][x];
        }
    }
}



/*
make_board
    Takes the string given by user and creates a 10 * 10 array.
    :: char* board_raw :: The string the board is constructed with.
    Returns a board_struct struct that contains the array.
*/
struct board_struct make_board(char* board_raw) {
    struct board_struct return_struct;

    // set the board to known state to help debugging
    for (int y0 = 0; y0 < MAX_BOARD_HEIGHT; y0++) {
        for (int x0 = 0; x0 < MAX_BOARD_WIDTH; x0++) {
            return_struct.state[y0][x0] = -1;
        }
    }

    int x = 0;
    int y = 0;
    int i = 0;

    while (board_raw[i] != '\0') {
        if (board_raw[i] == '/') {
            x = 0;
            y++;
        } else {
            return_struct.state[y][x] = (int)(board_raw[i] - '0');
            x++;
        }
        i++;
    }
    return_struct.height = y + 1;
    return_struct.width = x;

    return return_struct;
}



/*
print_board_struct
    Prints the state of given board_struct structure
    :: struct board_struct board :: Structure containing board
        to be printed.
*/
void print_board_struct(struct board_struct board) {
    for (int y = 0; y < board.height; y++) {
        for (int x = 0; x < board.width; x++) {
            printf("%d", board.state[y][x]);
        }
        printf("\n");
    }
}














