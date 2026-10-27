#include "logic.h"

/*
 * increment_num
 * Increments the int in a given base represented by the array
 *
 * :: int num[]    :: array to increment
 * :: char *argv[] :: length of num[]
 * :: species      :: base of the number
 *
 * Returns the struct settings
 */
void increment_num(int num[], int hole_num, int species) {
    int digit = hole_num - 1;

    while ((digit >= 0) && (num[digit] == species - 1)) {
        num[digit] = 0;
        digit--;
    }
    num[digit]++;
}

/*
 * matches_conditions
 * Checks if a given pattern fulfills given restrictions
 *
 * :: int num[]          :: The pattern to check
 * :: int hole_num       :: The lenght of the pattern 
 * :: int order_matters  :: If the pattern must be increasing monotonically
 * :: int replacement    :: If the pattern may have repeated elements
 *
 * Returns the result of the check
 */
int matches_conditions(int num[], int hole_num, int order_matters,
                       int replacement) {
    int error = 0;

    if ((has_replacement(num, hole_num) && !replacement) ||
        (!is_ordered(num, hole_num) && order_matters)) {
        error = 1;
    }
    return !error;
}

/*
 * has_replacement
 * Checks if given pattern has repeating elements
 *
 * :: int arr[]    :: pattern to check
 * :: int length   :: length of pattern
 *
 * Returns the result of the check
 */
int has_replacement(int arr[], int length) {
    int repeat = 0;
    int seen[MAX_SPECIES_COUNT] = {0};  

    for (int i = 0; i < length; i++) {
        if (seen[arr[i]]) {
            repeat = 1; 
        }
        seen[arr[i]] = 1;
    }
    return repeat;  
}

/*
 * is_ordered
 * Checks if given pattern is increasing monotonically
 *
 * :: int arr[]    :: pattern to check
 * :: int length   :: length of pattern
 *
 * Returns the result of the check
 */
int is_ordered(int arr[], int length) {
    int in_order = 1;
    for (int i = 0; i < length - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            in_order = 0;
        }
    }
    return in_order;
}
