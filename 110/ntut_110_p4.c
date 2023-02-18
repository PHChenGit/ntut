#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

int showTop(NODE* top) {
    return top->data;
}

void pushStack(NODE** top, int data) { //problem 4-1
    NODE* node;

    node = (NODE*) malloc(sizeof(NODE)); // problem 4-2
    if (node == NULL) {
        printf("Memory allocation failure!\n");
        exit(1);
    }
    node->data = data;
    node->next = *top;
    *top = node;
}

void showStack(NODE* top) {
    NODE* node = top;
    while (node != NULL) {
        printf("%d", node->data);
        node = node->next; // problem 4-3
    }
    printf("\n");
}

int popStack(NODE** top) { // problem 4-4
    int value;
    NODE* node = *top;
    if (node == NULL) {
        printf("Stack is empty!\n");
        exit(1);
    }
    value = (int)(node->data);
    *top = node->next; // problem 4-5
    free(node);
    return value;
}

int main() {
    NODE* stackTop = NULL;

    pushStack(&stackTop, 5);
    pushStack(&stackTop, 6);
    pushStack(&stackTop, 2);
    showStack(stackTop); // problem 4-6
    printf("problem 4-7: %d\n", popStack(&stackTop)); // problem 4-7
    printf("problem 4-8: %d\n", showTop(stackTop)); // problem 4-8
    return 0;
}