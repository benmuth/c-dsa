#include <stdio.h>
int main(void) {
    int i;
    // an array must be declared with a fixed size
    {
        float f[4];

        f[0] = 1.0;
        f[1] = 2.0;
        f[2] = 3.0;
        f[3] = 4.0;

        for (i = 0; i < 4; i++) {
            printf("%f\n", f[i]);
        }
    }

    {
        int a[100] = {0}; // initializes all uninitialized elements to 0
        for (i = 0; i < 10; i++) {
            printf("%i\n", a[i]);
        }
    }
    {
        int a[10] = {1, 2, 3, [7] = 6, 7, 8}; // set last 3 elements to 6, 7, 8
        /*
        this is equivalent (no explicit size)
        int a[] = {1, 2, 3, [7] = 6, 7, 8};
            */
        for (i = 0; i < 10; i++) {
            printf("%i\n", a[i]);
        }
    }
    /*
        Multidimensional arrays
    */
    {
        int a[2][5] = {{0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}};
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 5; col++) {
                printf("[%d][%d] = %d\n", row, col, a[row][col]);
            }
        }
    }

    // initialize specific locations
    {
        int a[3][3] = {[0][0] = 1, [1][1] = 1, [2][2] = 1};
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 5; col++) {
                printf("[%d][%d] = %d\n", row, col, a[row][col]);
            }
        }
    }

    /*
        Arrays and pointers
    */
    {
        int a[5] = {11, 5, 7, 18, 1};
        int *p;

        p = &a[0];

        printf("%d\n", *p); // prints '11'

        p = a; // same as p = &a[0] above
    }

    /*
        Arrays and functions
    */
    {
        // all equivalent function signatures
        void times2(int *a, int len);   // most idiomatic
        void times3(int a[5], int len); // the size of the array isn't enforced
                                        // by the compiler at all (except it has
                                        // to be >0)
        void times4(int a[], int len);

        // multidimensional arrays and functions

        // you have to pass sizes (except the first one)

        // both equivalent function signatures
        void print_2D_array(int a[2][3]);
        void print_2D_array(int a[][3]);
    }
}
