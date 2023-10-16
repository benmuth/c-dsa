#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nice_Array {
    int len;
    int list[10];
};

void sort_arr(struct Nice_Array arr) {
    if (arr.len < 2) {
        return;
    }

    // select the last element to always be the partition index
    int part_idx = arr.len - 1;
    printf("partition index: %d\n", part_idx);
    printf("partition index value: %d\n", arr.list[part_idx]);

    int second_ptr = 0;

    for (int i = 0; i < arr.len; i++) {
        printf("%d\n", i);
        // find an element greater than the partition element and remember it
        if (arr.list[i] > arr.list[part_idx]) {
            second_ptr = i;
        } else {
            continue;
        }
        // find an element less than the partition element and swap it with the
        // greater element
        if (arr.list[i] < arr.list[part_idx]) {
            int tmp = arr.list[i];
            arr.list[i] = arr.list[second_ptr];
            arr.list[second_ptr] = tmp;
            i = second_ptr + 1;
        }
    }

    // swap partition index with last greater element found
    int tmp = arr.list[part_idx];
    arr.list[part_idx] = arr.list[second_ptr];
    arr.list[second_ptr] = tmp;

    for (int i = 0; i < arr.len; i++) {
        // if (i == mid_idx) {
        //     printf("at the middle %d\n", i);
        // }
        printf("index %d val: %d\n", i, arr.list[i]);
    }
    printf("partition index value: %d\n", arr.list[part_idx]);

    return;
}

int main(void) {
    struct Nice_Array arr = {.len = 10, .list = {3, 4, 2, 7, 0, 1, 9, 7, 8, 5}};

    // int tmp = arr.list[0];
    // arr.list[0] = arr.list[6];
    // arr.list[6] = tmp;

    // for (int i = 0; i < arr.len; i++) {
    //     // if (i == mid_idx) {
    //     //     printf("at the middle %d\n", i);
    //     // }
    //     printf("index %d val: %d\n", i, arr.list[i]);
    // }
    sort_arr(arr);
}