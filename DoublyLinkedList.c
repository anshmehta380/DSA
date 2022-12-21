#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *lptr;
    struct node *rptr;
};
// Traversing is as same as
void traverseDoubly(struct node* head)
{
    struct node *p = head;
    while(p!=NULL)
    {
        printf("\nYour element is: %d",p->data);
        p = p->rptr; 
    }
}

int main()
{
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;

    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    first->lptr=NULL;
    first->data=10;
    first->rptr=second;

    second->data=20;
    second->lptr=first;
    second->rptr=third;

    third->lptr=second;
    third->data=30;
    third->rptr=fourth;

    fourth->lptr=third;
    fourth->data=40;
    fourth->rptr=NULL;
    traverseDoubly(first);
}