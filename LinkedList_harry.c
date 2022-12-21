#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// Accessing the linked list using a parameter which takes a pointer
//  the pointer which is given from the function is head.
void traverseLinkedList(struct Node *ptr)
{
    // Loop will continue until it finds the last node with NULL pointer.
    while (ptr != NULL)
    {
        // Printing the element of each node
        printf("Element is %d\n", ptr->data);
        // Now point the self pointer to next node;
        ptr = ptr->next;
    }
}
int main()
{
    // First Node self-pointer
    struct Node *head;
    // Second Node self-pointer
    struct Node *second;
    // Third Node self-pointer
    struct Node *third;

    // Allocated memory for linked list in heap
    // it will allocate the pointer head the memory required by structure Node
    // Each of the node will be allocated a int data and a pointer named next
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Data of first node
    head->data = 10;
    // Now the first node pointer will point to the second node
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    traverseLinkedList(head);

    return 0;
}