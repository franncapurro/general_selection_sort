# general_selection_sort
This C program takes an array of integers and sorts it with selection sorting algorithm with a customized order. 

To compile:
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort.c

Then:
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o sorter *.o main.c

To execute:
./sorter /input/example-unsorted.in

An array is loaded from a file with the following format:
<array_length>
<array_elem_1> <array_elem_2> <array_elem_3> ... <array_elem_N>

If you want to change the order in which the selection sort sorts, you should
modify the 'goes_before' function in the file 'sort.c'.
