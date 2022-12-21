#include<stdlib.h>
#include<stdio.h>
struct node 
{
    struct node *prev;
    int data;
    struct node *next;   
};
//Traverse a doubly linked list
void TraverseDoubly(struct node *head)
{
    struct node *p = head;
    while(p!=NULL)
    {
        printf("\nElement is: %d",p->data);
        p = p->next;
    }
}
struct node *deletionAtFirst(struct node *head)
{
    struct node *p = head;
    head = head->next;
    free(p);
    return head;
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *fourth = malloc(sizeof(struct node));
    head->prev=NULL;
    head->data=10;
    head->next=second;
    second->prev=head;
    second->data=20;
    second->next=third;
    third->prev=second;
    third->data=30;
    third->next=fourth;
    fourth->prev=third;
    fourth->data=40;
    fourth->next=NULL;
    head = deletionAtFirst(head);
    TraverseDoubly(head);
    return 0;
}