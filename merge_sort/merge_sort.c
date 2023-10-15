#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long NUM_ELEMENTS = 100000;

struct Node {
    int val;
    struct Node *next;
};

struct Node *create_node(int val) {
    struct Node *node = malloc(sizeof(struct Node));
    node->val = val;
    return node;
}

// create an array num_elements long filled with random integers
struct Node *create_list(int len) {
    struct Node *head = create_node(rand());
    struct Node *tmp = head;
    for (int i = 0; i < len; i++) {
        struct Node *next = create_node(rand());
        tmp->next = next;
        tmp = next;
    }
    return head;
}

void print_list(struct Node *head) {
    printf("PRINTING\n");
    int i = 0;
    while (head->next) {
        head = head->next;
        i++;
    }
    printf("list is %d elements long\n", i);
}

struct Node *find_mid(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node *merge_lists_rec(struct Node *list1, struct Node *list2) {
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }

    if (list1->val <= list2->val) {
        list1->next = merge_lists_rec(list1->next, list2);
        return list1;
    } else {
        list2->next = merge_lists_rec(list1, list2->next);
        return list2;
    }
}

struct Node *merge_lists_iter(struct Node *list1, struct Node *list2) {
    struct Node head;
    struct Node *tmp = &head;
    head.next = NULL;
    while (1) {
        if (!list1) {
            tmp->next = list2;
            break;
        }
        if (!list2) {
            tmp->next = list1;
            break;
        }

        if (list1->val <= list2->val) {
            tmp->next = list1;
            list1 = list1->next;
        } else {
            tmp->next = list2;
            list2 = list2->next;
        }
        tmp = tmp->next;
    }
    return head.next;
}

struct Node *sort_list(struct Node *head) {
    if (!head || !(head->next)) {
        return head;
    }

    struct Node *mid = find_mid(head);
    struct Node *right = mid->next;
    mid->next = NULL;
    struct Node *left = head;

    left = sort_list(left);
    right = sort_list(right);

    return merge_lists_iter(left, right);
}

bool has_cycle(struct Node *head) {
    if (!head) {
        return false;
    }
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if (!fast) {
            return false;
        }
        fast = fast->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

bool is_valid_sort(struct Node *head) {
    if (has_cycle(head)) {
        printf("has cycle\n");
        return false;
        // return false;
    }
    printf("no cycle\n");
    int prev_val = head->val;
    while (head->next) {
        head = head->next;
        int val = head->val;
        assert(val >= prev_val);
        if (val < prev_val) {
            return false;
        }
        prev_val = val;
    }
    printf("VALIDATED\n");
    return true;
}

void free_list(struct Node *head) {
    while (head->next) {
        struct Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    srand(time(NULL));

    printf("CREATING\n");
    struct Node *head = create_list(NUM_ELEMENTS);

    printf("SORTING\n");
    clock_t start = clock(), diff;
    printf("start: %lu\n", start);
    head = sort_list(head);
    diff = clock() - start;
    printf("diff: %lu\n", diff);
    printf("clocks/sec: %lu\n", CLOCKS_PER_SEC);
    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("merge sort for %lu elements: %ds %dms\n", NUM_ELEMENTS, msec / 1000,
           msec % 1000);
    printf("VALIDATING\n");
    is_valid_sort(head);

    free_list(head);
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
