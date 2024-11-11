// Include the standard input/output library header file.
// This provides functions like printf() and scanf() for input/output operations.
#include <stdio.h>
// Include the standard library header file.
// This provides functions like malloc() and free() for memory allocation.
#include <stdlib.h>

// Define the structure for a node in the linked list
// Contains an integer data field and a pointer to the next node
struct Node 
{
    int data;
    struct Node* next;
};

// Function declarations
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int data);
void traverseList(struct Node* head);

// Creates a new node with the given data
// Returns a pointer to the newly created node
struct Node* createNode(int data)
{
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Set the data field of the new node
    newNode->data = data;
    // Initialize the next pointer to NULL
    newNode->next = NULL;
    return newNode;
}

// Inserts a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) 
{
    // Create a new node
    struct Node* newNode = createNode(data);
    // Set the next pointer of new node to current head
    newNode->next = *head;
    // Update head to point to the new node
    *head = newNode;
}

// Inserts a new node at the end of the list
void insertAtEnd(struct Node** head, int data) 
{
    // Create a new node
    struct Node* newNode = createNode(data);
    // If list is empty, make new node the head
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Traverse to the end of the list
    struct Node* temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    // Add new node at the end
    temp->next = newNode;
}

// Deletes a node with the given data from the list
void deleteNode(struct Node** head, int data) 
{
    // Check if list is empty
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete node.\n");
        return;
    }

    // Initialize temporary pointers for traversal
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Search for node with given data
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }
    
    // If node not found
    if (temp == NULL)
    {
        printf("Node with data %d not found.\n", data);
        return;
    }

    // If node to delete is head
    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        // Skip over the node to delete
        prev->next = temp->next;
    }
    // Free the memory of deleted node
    free(temp);
}

// Traverses the list and prints all nodes
void traverseList(struct Node* head)
{
    // Use temporary pointer to traverse
    struct Node* temp = head;
    while (temp != NULL)
    {
        // Print current node's data
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the linked list implementation
int main()
{
    // Initialize empty list
    struct Node* head = NULL;
    
    // Insert nodes at beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);

    // Insert nodes at end
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printf("Linked list after inserting at end: ");
    traverseList(head);

    // Delete a node and print result
    deleteNode(&head, 20);
    printf("Linked list after deleting node with data 20: ");
    traverseList(head);
    return 0;
}