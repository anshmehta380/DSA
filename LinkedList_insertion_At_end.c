#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverseLinkedList(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("\nYour data is %d",ptr->data);
        ptr = ptr->next;
    }
}
struct node *insertAtEnd(struct node*head,int val)
{
    struct node *p = head;
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next=ptr;
    ptr->data = val;
    ptr->next = NULL;
    return head;
}
int main()
{
    struct node *first;
    struct node *second;
    struct node *third;
    first = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));

    first->data=10;
    first->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;

    // traverseLinkedList(first);
    first = insertAtEnd(first,40);
    traverseLinkedList(first);
    return 0;
}