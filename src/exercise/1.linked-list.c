#include <stdio.h>
#include <stdlib.h>


/*
Exercise 1: Linked List
Description:
    Implement a linked list with the following functions:
        1. printList
        2. insertAtBeginning
        3. reverseList
        4. main function to test the implementation

Tips:
"->" is used to access the members of a struct through a pointer.
"malloc" is used to allocate a single block of memory of a given size.
"sizeof" is used to get the size of a variable or a type in bytes.
"free" is used to release the memory allocated by malloc.
"NULL" is a constant macro that represents a null pointer.
"int" is a data type that represents an integer.
"struct" is a keyword that is used to define a new data type, 
which is a collection of variables of different data types.
** is used to pass a pointer to a pointer to a function.

*/


struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head);
void reverseList(struct Node** head);
void insertAtBeginning(struct Node** head, int data);

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

/*TODO: Implement a function to reverse the linked list*/
void reverseList(struct Node** head) {

}

int main() {
    struct Node* head = NULL;
    /*TODO: Add nodes to the linked list*/

    /*TODO: Call the reverse function*/

    return 0;
}
