#include <stdbool.h>

/*
Swaps two elements in an array.
*/
static void swap(int a[], unsigned int i, unsigned int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

/*
This function defines the order in which the selection sort is going to be
executed.
*/
static bool goes_before(int x, int y) {
    bool ans = (x <= y);
    return ans;
}

/*
This function returns the position into which the element that's in the i position
should be placed.
*/
static unsigned int select_position(int a[], unsigned int i, unsigned int length) {
    unsigned int position = i;
    for(unsigned int j = i + 1; j < length; j++) {
        if(goes_before(a[j], a[position])) {
            position = j;
        }
    }
    return(position);
}

/*
    This function calls the swap function for every element that must be
    swaped.
*/
void g_selection_sort(int a[], unsigned int length) {
    unsigned int pos_to_swap;
    for(unsigned int i = 0; i < length; i++) {
        pos_to_swap = select_position(a, i, length);
        swap(a, i, pos_to_swap);
    }
}
