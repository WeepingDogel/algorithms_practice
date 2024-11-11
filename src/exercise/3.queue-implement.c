#include <stdio.h>
#include <stdlib.h>

/*
Exercise 3: Queue
description:
    Implement a queue with the following functions:
        1. enqueue
        2. dequeue
        3. main function to test the implementation

Tips:
    "->" is used to access the members of a struct through a pointer.
    "malloc" is used to allocate a single block of memory of a given size.
    "sizeof" is used to get the size of a variable or a type in bytes.
    "free" is used to release the memory allocated by malloc.
    "NULL" is a constant macro that represents a null pointer.
    "int" is a data type that represents an integer.
*/

/*TODO: Define the queue structure*/
struct Queue {
    int data;
    struct Queue* next;
};

/*TODO: Declare the functions*/
void enqueue(struct Queue** front, struct Queue** rear, int data);
int dequeue(struct Queue** front, struct Queue** rear);
void printQueue(struct Queue* front);

/*TODO: Implement the enqueue function*/
void enqueue(struct Queue** front, struct Queue** rear, int data) {
    struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*rear == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

/*TODO: Implement the dequeue function*/
int dequeue(struct Queue** front, struct Queue** rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Queue* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return data;
}

void printQueue(struct Queue* front) {
    struct Queue* temp = front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/*TODO: Implement the main function to test the implementation*/
int main(){
    /*TODO: Create a queue and test the implementation*/
    struct Queue* front = NULL;
    struct Queue* rear = NULL;
    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    printQueue(front);
    
    printf("Dequeued: %d\n", dequeue(&front, &rear));
    printQueue(front);
    
    return 0;
}