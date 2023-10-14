#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node *create_node(int val) {
    struct Node *node = malloc(sizeof(struct Node));
    node->val = val;
    return node;
}

struct Node *create_list(int len) {
    struct Node *head = create_node(rand());
    printf("head address: %p\n", head);
    struct Node *tmp = head;
    for (int i = 0; i < len; i++) {
        struct Node *next = create_node(rand());
        tmp->next = next;
        tmp = next;
    }
    return head;
}

void traverse_list(struct Node *head) {
    if (!head) {
        return;
    }
    printf("current node address: %p\n", head);
    printf("current node value: %d\n", head->val);
    traverse_list(head->next);
}

int main(void) {
    printf("node size: %lu\n", sizeof(struct Node));
    srand(time(NULL));
    int rand_val = rand();
    struct Node *node = create_node(rand_val);
    printf("node value: %d\n", node->val);

    struct Node *head = create_list(10);
    traverse_list(head);
    return 0;
}
