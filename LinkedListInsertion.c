#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void TraverseLinkedList(struct node *ptr)
{
    while(ptr!=NULL)
    {
         printf("\nYour Linked list elements are: %d",ptr->data);
        ptr = ptr->next;
    }    
}

struct node *insertionAtFront(struct node *head,int val)
{
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = head;
    return ptr;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    
    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;

    head = insertionAtFront(head,50);
    TraverseLinkedList(head);
    return 0;
}