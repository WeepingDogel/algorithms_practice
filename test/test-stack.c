#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

// Function declarations
struct StackNode* createNode(int data);
void push(struct StackNode** stack, int data);
int pop(struct StackNode** stack); 
void printStack(struct StackNode* stack);
int peek(struct StackNode* stack);
void isEmpty(struct StackNode* stack);

// Create a new node
// @param data: int
// @return: struct StackNode*
// @description: Create a new node with the given data and return a pointer to it
struct StackNode* createNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Push a new node to the stack
// @param stack: struct StackNode**
// @param data: int
// @return: void
// @description: Push a new node to the stack
void push(struct StackNode** stack, int data) {
    struct StackNode* newNode = createNode(data);
    newNode->next = *stack;
    *stack = newNode;
}

// Pop a node from the stack
// @param stack: struct StackNode**
// @return: int
// @description: Pop a node from the stack and return the data of the node.
int pop(struct StackNode** stack) {
    if (*stack == NULL) {
        return -1;
    }
    struct StackNode* temp = *stack;
    int data = temp->data;
    *stack = temp->next;
    free(temp);
    return data;
}

// Print the stack with a blank in the middle.
// @param stack: struct StackNode*
// @return: void
// @description: Print the stack with a blank in the middle.
void printStack(struct StackNode* stack) {
    while (stack != NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

// peek the top of the stack
// @param stack: struct StackNode*
// @return: int
// @description: Peek the top of the stack and return the data of the node.
int peek(struct StackNode* stack) {
    return stack->data;
}

// Check if the stack is empty
// @param stack: struct StackNode*
// @return: void
// @description: Check if the stack is empty
void isEmpty(struct StackNode* stack) {
    if (stack == NULL) {
        printf("The stack is empty.\n");
    }
}

int main() {
    struct StackNode* stack = NULL;
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    printStack(stack);
    printf("We can only pop the top element of the stack.\nBecause we don't have a pointer to the second to top element.\n");
    printf("The top element is: %d\n", peek(stack));
    printf("Now let's pop the top element: %d\n", pop(&stack));
    printStack(stack);
    printf("Now the top element is: %d\n", peek(stack));
    // pop all elements
    while (stack != NULL) {
        printf("Pop: %d\n", pop(&stack));
    }
    isEmpty(stack);
    return 0;
}