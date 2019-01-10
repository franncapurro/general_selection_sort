#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"
#include "sort.h"

#define MAX_SIZE 100000

/*
This function checks whether the program is executed with exactly one
argument.
*/
char* check_filepath(int argc, char* argv[]) {
    if(argc != 2){
        printf("The program must have exactly one argument.");
        exit(EXIT_FAILURE);
    }
    char* result = argv[1];
    return(result);
}

int main(int argc, char* argv[]) {
    char* filepath = check_filepath(argc, argv);
    /*The array that will contain the array of the file.*/
    int array[MAX_SIZE];
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    g_selection_sort(array, length);
    assert(array_is_sorted(array, length));
    screen_array(array, length);
    /*The following lines are to ensure the sorted array contains the same
elements of the original.*/
    int copy[MAX_SIZE];
    array_copy(copy, array, length);
    assert(its_permutation(copy, array, length));
    return(EXIT_SUCCESS);
}
