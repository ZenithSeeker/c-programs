#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>

#define MAX_SPECIES_COUNT 1024

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
int matches_conditions(int num[], int hole_num, int order_matters, int replacement);

/*
 * is_ordered
 * Checks if given pattern is increasing monotonically
 *
 * :: int arr[]    :: pattern to check
 * :: int length   :: length of pattern
 *
 * Returns the result of the check
 */
int is_ordered(int arr[], int length);

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
void increment_num(int num[], int hole_num, int species);

/*
 * has_replacement
 * Checks if given pattern has repeating elements
 *
 * :: int arr[]    :: pattern to check
 * :: int length   :: length of pattern
 *
 * Returns the result of the check
 */
int has_replacement(int arr[], int length);

#endif