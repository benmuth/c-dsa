#include <linux/limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *a, int idx_1, int idx_2) {
    int tmp = a[idx_1];
    a[idx_1] = a[idx_2];
    a[idx_2] = tmp;
}

// p points to the first element, r points to the last element (which is the
// pivot)
int partition(int *a, int p, int r) {
    // printf("partitioning\n");
    // q eventually points to the pivot
    // until the pivot is swapped into place, q points to the
    // first element in the array found to be greater than the pivot value.
    // if we find a new element that's greater than the pivot value, it's
    // swapped with a[q] and we increment q so that all elements found to be
    // greater than the pivot value remain to the right of q
    int q = p;
    // j is our iterating variable
    int j = p;

    // printf("subarray start idx: %d \t subarray end idx: %d\n", p, r);

    // look at every element besides the pivot
    while (j < r) {
        // printf("iterator value: %d, pivot index: %d\n", j, r);
        // if a[j] > pivot element, a[j] is already in the right place, so just
        // inc j
        if (a[j] >= a[r]) {
            j++;
        }
        // a[j] is in wrong place, swap it with first element in Greater group
        // (a[j] > a[r]) and slide window of Greater group
        if (a[j] < a[r]) {
            swap(a, j, q);
            j++;
            q++;
        }
    }

    // finally, swap the pivot value (a[r]) with the element in between the
    // Greater and Less groups a[q]
    swap(a, r, q);

    return q;
}

// sub array range is [p, r]. p and r are both indices
void quick_sort(int *a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);

        // printf("partition index: %d\n", q);

        // for (int i = 0; i <= r; i++) {
        //     printf("i: %d \t val: %d\n", i, a[i]);
        // }

        quick_sort(a, p, q - 1);
        quick_sort(a, q + 1, r);
    }
    return;
    // printf("partition index: %d\n", part_idx);

    // return;
}

bool validate_sort(int *a, int len);

int *generate_array(int len) {
    // printf("1");
    int cap = 0;
    int *a = NULL;
    int i;

    for (i = 0; i < len; i++) {
        // printf("i: %d\tcap: %d\n", i, cap);
        if (i >= cap) {
            cap++;
            cap *= 2;

            a = realloc(a, sizeof(int) * cap);
            if (a == NULL) {
                printf("NOT ENOUGH MEMORY");
                return NULL;
            }
        }
        a[i] = rand();
    }

    // printf("2");
    return a;
}

long NUM_ELEMENTS = 10000000;
int main(void) {
    srand(time(NULL));
    int r = NUM_ELEMENTS - 1;
    // int a[] = {3, 8, 2, 7, 0, 1, 9, 7, 4, 5};
    int *a = generate_array(NUM_ELEMENTS);

    clock_t start = clock(), diff;

    quick_sort(a, 0, r);

    diff = clock() - start;

    printf("start: %lu\n", start);
    printf("diff: %lu\n", diff);
    printf("clocks/sec: %lu\n", CLOCKS_PER_SEC);
    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("quick sort for %lu elements: %ds %dms\n", NUM_ELEMENTS, msec / 1000,
           msec % 1000);
    printf("sorting done!\n");
    // for (int i = 0; i <= r; i++) {
    //     printf("i: %d \t val: %d\n", i, a[i]);
    // }
    if (!validate_sort(a, NUM_ELEMENTS)) {
        printf("failed to sort!\n");
    }
}

bool validate_sort(int *a, int len) {
    if (len < 2) {
        return true;
    }
    int prev = INT32_MIN;
    for (int i = 0; i < len; i++) {
        if (a[i] < prev) {
            return false;
        }
        prev = a[i];
    }
    return true;
}