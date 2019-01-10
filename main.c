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
    int array[MAX_SIZE];
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    g_selection_sort(array, length);
    screen_array(array, length);
    return(EXIT_SUCCESS);
}
