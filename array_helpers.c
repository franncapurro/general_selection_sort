#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    The elements of the array that's in the file located at 'filepath' are
    copied into the array 'a'.
    The length of the array must be lower or equal to "max_size".
    The functions returns the length of the array.
*/
unsigned int array_from_file(int array[], unsigned int max_size, const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if(file == NULL) {
        printf("Opening file error.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0;
    unsigned int size = 0;
    //the size of the array is in the file
    int res = fscanf(file, " %u ", &size);
    if(res != 1) {
        printf("Invalid array.\n");
        exit(EXIT_FAILURE);
    }
    if(size > max_size) {
        printf("The size of the array must be lower or equal to %d.\n", max_size);
        exit(EXIT_FAILURE);
    }
    while(i < size) {
        res = fscanf(file, " %d ", &array[i]);
        if(res != 1) {
            printf("The arrays is not correctly formated.\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    fclose(file);
    return(size);
}

/*
This function displays an array on the terminal screen.
*/
void screen_array(int a[], unsigned int length) {
    for(unsigned int i = 0; i < length; i++) {
        printf("%i ", a[i]);
    }
    printf("\n");
}

/*
Copies an array onto another.
*/
void array_copy(int copy[], int array[], unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        copy[i] = array[i];
    }
}

/*
Counts how many times a specif value appears in an array.
*/
unsigned int count_value(int a[], unsigned int length, int value) {
    unsigned int count = 0;
    for(unsigned int i = 0; i < length; i++) {
        if(a[i] == value) {
            count++;
        }
    }
    return(count);
}

/*
Checks whether the array 'b' is a permutation of the array 'a'.
*/
bool its_permutation(int a[], int b[], unsigned int length) {
    unsigned int i = 0;
    bool ans = true;
    while(i < length && ans) {
        ans = count_value(a, length, a[i]) == count_value(b, length, b[i]);
        i++;
    }
    return(ans);
}
