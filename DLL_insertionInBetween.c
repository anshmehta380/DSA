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
struct node *insertInEmptyAtBeginning(struct node *head,int val)
{
struct node *temp = (struct node*)malloc(sizeof(struct node));
temp->next = head;
temp->data= val;
head->prev = temp;
head = temp;
return head;
}
struct node *insertInBetweenAfter(struct node* head,int val,int index)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *p = head;
    struct node *p2;
    int i=1; 
    while(i!=index)
    {
        p = p->next;
        i++;
    }
    if(index==0)
    {
        head = insertInEmptyAtBeginning(head,val);
    }
    else
    {
    temp->data=val;
    p2 = p->next;
    temp->next = p2;
    temp->prev = p;
    p2->prev = temp;
    p->next = temp;
    }
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
    second->data=30;
    second->next=third;
    third->prev=second;
    third->data=40;
    third->next=fourth;
    fourth->prev=third;
    fourth->data=50;
    fourth->next=NULL;
    head = insertInBetweenAfter(head,20,1);
    TraverseDoubly(head);
    return 0;
}