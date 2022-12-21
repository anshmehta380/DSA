#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void TraverserLinkedList(struct node *head)
{
    while(head!=NULL)
    {
        printf("\nYour elements are %d",head->data);
        head = head->next;
    }
}

struct node *insertionBeforeNode(struct node *head,int index,int val)
{
    struct node *p = head;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    int i =1;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
int main()
{
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;
    first = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node*) malloc(sizeof(struct node));

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next=NULL;

    //TraverserLinkedList(first);
    first = insertionBeforeNode(first,2,3);
    TraverserLinkedList(first);
    return 0;
}