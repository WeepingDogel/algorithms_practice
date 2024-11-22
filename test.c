/*
I want to practice the general data structure and algorithm questions.
So I write the test code here.

1. Implement a stack using linked list.
2. Implement a queue using linked list.
3. Implement a binary search tree.
4. Implement a binary search tree (BST) and a binary tree.
*/

#include <stdio.h>
#include <stdlib.h>

// Declare the structs
struct Stack {
    int data;
    struct Stack* next;
};

struct Queue {
    int data;
    struct Queue* next;
};
// Declare the functions
struct Stack* createStack();
void push(struct Stack* stack, int data);
void pop(struct Stack* stack);
void printStack(struct Stack* stack);
void reverseStack(struct Stack* stack);
struct Queue* createQueue();
void enqueue(struct Queue* queue, int data);
void dequeue(struct Queue* queue);
void printQueue(struct Queue* queue);


// Implement the functions
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->next = NULL;
    return stack;
}

void push(struct Stack* stack, int data) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = data;
    newNode->next = stack->next;
    stack->next = newNode;
}

void pop(struct Stack* stack) {
    if (stack->next == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Stack* temp = stack->next;
    stack->next = temp->next;
    free(temp);
}

void printStack(struct Stack* stack) {
    struct Stack* temp = stack->next;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseStack(struct Stack* stack) {
    struct Stack* prev = NULL;
    struct Stack* current = stack->next;
    struct Stack* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    stack->next = prev;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->next = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->next == NULL) {
        queue->next = newNode;
    } else {
        struct Queue* temp = queue->next;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void dequeue(struct Queue* queue) {
    if (queue->next == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Queue* temp = queue->next;
    queue->next = temp->next;
    free(temp);
}

void printQueue(struct Queue* queue) {
    struct Queue* temp = queue->next;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseQueue(struct Queue* queue) {
    struct Queue* prev = NULL;
    struct Queue* current = queue->next;
    struct Queue* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    queue->next = prev;
}


int main() {
    printf("Stack:\n");
    struct Stack* stack = createStack(); 
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printStack(stack);
    // reverseStack(stack);
    // printStack(stack);
    pop(stack);
    printStack(stack);
    printf("Queue:\n");
    struct Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueue(queue);
    // reverseQueue(queue);
    // printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    return 0;
}