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
struct node *deletionBetweenNode(struct node *head,int val)
{
    struct node *p = head;
    struct node *prevp;
    struct node *nextp;
    while(p->data!=val)
    {
        p = p->next;
    }
    prevp = p->prev;
    nextp = p->next;
    prevp->next = nextp;
    nextp->prev = prevp;
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
    head = deletionBetweenNode(head,20);
    TraverseDoubly(head);
    return 0;
}