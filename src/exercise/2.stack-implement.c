#include <stdio.h>
#include <stdlib.h>
/*
Exercise 2: Stack
description:
    Implement a stack with the following functions:
        1. push
        2. pop
        3. main function to test the implementation

Tips:
    "->" is used to access the members of a struct through a pointer.
    "malloc" is used to allocate a single block of memory of a given size.
    "sizeof" is used to get the size of a variable or a type in bytes.
    "free" is used to release the memory allocated by malloc.
    "NULL" is a constant macro that represents a null pointer.
    "int" is a data type that represents an integer.
    "struct" is a keyword that is used to define a new data type, 
    which is a collection of variables of different data types.
*/

struct Stack {
    int data;
    struct Stack* next;
};

/* Declare functions*/
void push(struct Stack** top, int data);
void printStack(struct Stack* top);
int pop(struct Stack** top);


/*TODO: Implement function to push data onto the stack*/
void push(struct Stack** top, int data) {
    /*TODO*/
    // Allocate memory for the new node.
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    // Set the data of the new node.
    newNode->data = data;
    // Set the next pointer of the new node to the current top of the stack.
    newNode->next = *top;
    // Update the top of the stack to the new node.
    *top = newNode;
}

/*TODO: Implement function to pop data from the stack*/
int pop(struct Stack** top) {
    /*TODO*/
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    // Store the data of the top node in a variable.
    int data = (*top)->data;
    // Update the top of the stack to the next node.
    *top = (*top)->next;
    // Return the data of the top node.
    return data;
}

void printStack(struct Stack* top) {
    struct Stack* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Stack* top = NULL;
    // push 10 items
    for (int i = 0; i < 10; i++) {
        push(&top, i);
    }
    printStack(top);
    
    // Pop 5 items, and print the stack after each pop
    for (int i = 0; i < 5; i++) {
        printf("Popped: %d\n", pop(&top));
        printStack(top);
    }
    return 0;
}

// Key points:
// 1. The stack is a linear data structure that follows the Last In First Out (LIFO) principle.
// 2. The top of the stack is the last node added to the stack.
// 3. The bottom of the stack is the first node added to the stack.
// 4. The stack is a dynamic data structure, meaning it can grow or shrink as needed at runtime.
// 5. The stack is a limited data structure, meaning it has a fixed number of operations.

