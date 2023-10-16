#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int idx_1, int idx_2) {
    int tmp = a[idx_1];
    a[idx_1] = a[idx_2];
    a[idx_2] = tmp;
}

// p points to the first element, r points to the last element (which is the
// pivot)
int partition(int *a, int p, int r) {
    // q eventually points to the pivot
    // until the pivot is swapped into place, q points to the
    // first element in the array found to be greater than the pivot value.
    // if we find a new element that's greater than the pivot value, it's
    // swapped with a[q] and we increment q so that all elements found to be
    // greater than the pivot value remain to the right of q
    int q = p;
    // j is our iterating variable
    int j = p;

    // look at every element besides the pivot
    while (j < r) {
        if (a[j] > a[r]) {
            j++;
        }
        if (a[j] < a[r]) {
            swap(a, j, q);
            j++;
            q++;
        }
    }

    // swap the pivot value (a[r]) with the element in between the Greater and
    // Less groups a[q]
    swap(a, r, q);

    return q;
}

// sub array range is [p, r). p and r are both indices
void sort_arr(int *a, int p, int r) {
    if ((r - p + 1) < 2) {
        return;
    }

    int part_idx = partition(a, p, r);

    for (int i = 0; i <= r; i++) {
        printf("i: %d \t val: %d\n", i, a[i]);
    }

    printf("partition index: %d\n", part_idx);

    return;
}

int main(void) {
    int a[] = {3, 4, 2, 7, 0, 1, 9, 7, 8, 5};
    int r = 9;
    // for (int i = 0; i <= r; i++) {
    //     printf("i: %d \t val: %d\n", i, a[i]);
    // }
    sort_arr(a, 0, r);
}