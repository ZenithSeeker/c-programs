#include "arg_parse.h"

/*
 * arg_parse
 * Parses args and returns a settings struct containing the user's choices
 *
 * :: int argc    :: count of arguments
 * :: char *argv[]      :: array of argument strings
 *
 * Returns the struct settings
 */
struct settings arg_parse(int argc, char *argv[]) {
    int opt;
    struct settings chosen = {0};  // defaults: permutations, without replacement
    struct option long_options[] = {
        {"permutations", no_argument, NULL, 'p'},
        {"combinations", no_argument, NULL, 'c'},
        {"with-replacement", no_argument, NULL, 'r'},
        {"without-replacement", no_argument, NULL, 'o'},
        {"num-elements", required_argument, NULL, 'n'},
        {NULL, 0, NULL, 0}};

    while ((opt = getopt_long(argc, argv, "pcron:", long_options, NULL)) !=
           -1) {
        switch (opt) {
            case 'p':
                chosen.order_matters = 0;
                break;
            case 'c':
                chosen.order_matters = 1;
                break;
            case 'r':
                chosen.is_replacement = 1;
                break;
            case 'o':
                chosen.is_replacement = 0;
                break;
            case 'n':
                chosen.hole_num = atoi(optarg);
                break;
            default:
                printf("Bad input\n");
                exit(1);
        }
    }

    if (optind + 2 > argc) {
        printf("Usage: counting [-p|-c] [-r|-o] -n NUM input_file output_file\n");
        exit(1);
    }
    if (chosen.hole_num < 1 || chosen.hole_num > MAX_ARR_LENGTH) {
        printf("-n must be between 1 and %d\n", MAX_ARR_LENGTH);
        exit(1);
    }
    chosen.file_in = argv[optind];
    chosen.file_out = argv[optind + 1];

    return chosen;
}

