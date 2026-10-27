#ifndef STRUCT_H
#define STRUCT_H

#define MAX_BOARD_WIDTH 10
#define MAX_BOARD_HEIGHT 10

struct board_struct {
    int width;
    int height;
    int state[MAX_BOARD_HEIGHT][MAX_BOARD_WIDTH];
};

struct settings {
    int lower;
    int upper;
    int wrap;
    int total;
    int step;
    char* board_raw;
};

#endif
