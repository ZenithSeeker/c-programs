#include <main.h>

int main(int argc, char const* argv[]) {
  struct settings chosen = arg_parse(argc, (char**)argv);
  FILE* file_in = fopen(chosen.file_in, "r");
  FILE* file_out = fopen(chosen.file_out, "w");
  int bird_indexes[MAX_SPECIES_COUNT];
  int num[MAX_ARR_LENGTH] = {0};

  // check the files opened before reading from them
  if (file_in == NULL || file_out == NULL) {
    printf("Error: could not open input or output file\n");
    return 1;
  }

  int species = find_index(file_in, bird_indexes, ' ');

  //iterate over all possible permutations and "birdify" valid solutions
  for (int i = 0; i < pow(species, chosen.hole_num); ++i) {
    if (matches_conditions(num, chosen.hole_num, chosen.order_matters,
                           chosen.is_replacement)) {
      birdify(num, chosen.hole_num, file_in, file_out, bird_indexes);
    }
    increment_num(num, chosen.hole_num, species);
  }

  fclose(file_in);
  fclose(file_out);
  return 0;
}
