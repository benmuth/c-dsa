#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NUM_ELEMENTS = 10;

struct Node {
    char val;
    struct Node *next;
};

// create an array num_elements long filled with random integers
struct Node *create_list(int num_elements) {
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->val = rand();
    struct Node *head = tmp;
    for (int i = 0; i < num_elements; i++) {
        struct Node *next = (struct Node *)malloc(sizeof(struct Node));
        next->val = rand();
        printf("new node val: %d\n", next->val);
        printf("new node address: %p\n", &next);
        tmp->next = next;
    }

    return head;
}

void iterate_through_list(struct Node *head) {
    printf("ITERATING\n");
    int i = 0;
    while (head->next) {
        printf("node value: %d\n", head->val);
        printf("next address %p\n", head->next);
        head = head->next;
        i++;
    }
    printf("list is %d elements long\n", i);
}

int main(void) {
    // use time as seed for random list node values
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    srand(ts.tv_sec);

    // struct list_node tmp = {.val = rand()};
    // struct list_node tmp2 = {.val = rand(), .next = &tmp};

    // printf("%d\n", tmp2.next == NULL);

    struct Node *head = create_list(NUM_ELEMENTS);
    // iterate_through_list(head);
    printf("first element value: %d\n", head->val);
    return 0;
}

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
