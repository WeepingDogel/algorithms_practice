#include <stdio.h>
#include <stdlib.h>

// Pointer: A pointer is a variable that stores the memory address of another variable.
// It allows you to directly access and manipulate the value of the variable it points to.
// In this case, the pointer is used to point to the next node in the linked list.
// The pointer is a struct pointer that points to a struct Node.    

// The struct Node contains two fields:
// 1. int data: an integer value stored in the node.
// 2. struct Node* next: a pointer to the next node in the linked list. 
// The next pointer is used to link the current node to the next node in the list.
// If the next pointer is NULL, it means the current node is the last node in the list.
// The linked list is a dynamic data structure, meaning it can grow or shrink as needed at runtime.
// The linked list is a linear data structure, meaning it consists of a sequence of nodes in a single line.
// The first node is called the head of the linked list, and the last node is called the tail of the linked list.

struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void reverseList(struct Node** head);
void traverseList(struct Node* head);
void deleteNode(struct Node** head, int data);


struct Node 
{
    int data; // data stored in the node.
    struct Node* next;  // pointer to the next node.
};

// Node* is a pointer to a struct Node.
struct Node* createNode(int data) 
{
    // Allocate memory for the new node.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Set the data of the new node.
    newNode->data = data;
    // Set the next pointer of the new node to NULL.
    newNode->next = NULL;
    // Return the pointer to the new node.
    return newNode;
}

// "->" is used to access the members of a struct through a pointer.
// "*" is used to declare a pointer to a variable.
// "**" is used to declare a pointer to a pointer.
// "malloc" is used to allocate memory dynamically at runtime.
// "sizeof" is used to get the size of a variable or a type in bytes.
// "free" is used to release the memory allocated by malloc.
// "NULL" is a constant macro that represents a null pointer.
// "int" is a data type that represents an integer.
// "struct" is a keyword that is used to define a new data type, 
// which is a collection of variables of different data types.

void insertAtBeginning(struct Node** head, int data)
{
    // Allocate memory for the new node.
    struct Node* newNode = createNode(data);
    // Set the next pointer of the new node to the current head of the list.
    newNode->next = *head;
    // Update the head pointer to point to the new node.
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    // Allocate memory for the new node.    
    struct Node* newNode = createNode(data);
    // If the list is empty, set the head pointer to the new node.
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    // Traverse the list to find the last node.
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    // Set the next pointer of the last node to the new node.
    current->next = newNode;
}

void reverseList(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;   
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void traverseList(struct Node* head)
{
    // Initialize a pointer to the head of the list.    
    struct Node* current = head;
    // Traverse the list and print the data of each node.
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteNode(struct Node** head, int data) 
{
    // Initialize a pointer to the head of the list.
    struct Node* current = *head;
    // Initialize a pointer to the previous node.   
    struct Node* prev = NULL;
    // If the current node is not NULL and its data matches the target data,
    // update the head pointer to point to the next node.
    if (current != NULL && current->data == data) 
    {
        // Update the head pointer to point to the next node.
        *head = current->next;
        // Free the memory allocated for the current node.
        free(current);
        // Return from the function.
        return;
    }
    // Traverse the list to find the node with the target data. 
    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }
    // If the node with the target data is not found, return from the function.
    if (current == NULL)
    {
        printf("Node with data %d not found.\n", data);
        return;
    }
    // Set the next pointer of the previous node to the next pointer of the current node.
    prev->next = current->next;
    // Free the memory allocated for the current node.
    free(current);

}   

int main() 
{
    struct Node* head = NULL;

    // Inserting nodes at the beginning of the list.
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);

    // Inserting nodes at the end of the list.
    // insertAtEnd(&head, 30);
    // insertAtEnd(&head, 40);
    
    // Traversing the list and printing the data of each node.
    printf("Linked list: ");
    traverseList(head);

    // Reversing the list.
    reverseList(&head);
    printf("Linked list after reversing: ");
    traverseList(head);

    // Deleting a node from the list.
    deleteNode(&head, 2);
    printf("Linked list after deleting node with data 2: \n");
    traverseList(head);
    return 0;
}


