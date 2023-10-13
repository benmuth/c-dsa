#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int NUM_ELEMENTS = 10;

// example recursive function
int fib(size_t n) {
    if (n == 1) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

// create an array num_elements long filled with random integers
char *create_list(int num_elements) {
}

int main(void) {
    char *rand_nums = create_list(NUM_ELEMENTS);
    for (size_t i = 0; i < NUM_ELEMENTS; i++) {
        printf("%d\n", rand_nums[i]);
    }
    return 0;
}

char *sort_array(char array) {
    int len = sizeof(array) / sizeof(array[0]);
    int mid = len / 2 char *left = malloc(mid);

    return merge(left, right);
}

char *merge(array1, array2)

    /*
        Merge Sort overview
        given a list

        sort_list:
            check if a list is empty or 1 element long
                if so, it's sorted, return it
            split list down the middle into left and right sides
            call sort_list on left and right sides
            merge the two sorted lists
    */
