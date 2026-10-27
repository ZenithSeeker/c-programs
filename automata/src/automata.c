#include <stdio.h>

#include "board.h"
#include "parse_arg.h"
#include "struct.h"

int main(int argc, char** argv) {
    struct settings chosen = parse_arg(argc, argv);
    struct board_struct board = make_board(chosen.board_raw);

    print_board_struct(board);
    
    for (int i = 1; i <= chosen.total; i++) {
        board = update_board(board, chosen);
        if ((i % chosen.step) == 0) {
            printf("\n");
            print_board_struct(board);
        }
    }

    return 0;
}