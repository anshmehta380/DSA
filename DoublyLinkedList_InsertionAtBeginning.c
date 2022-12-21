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
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->prev=NULL;
    head->data=10;
    head->next=NULL;
    head = insertInEmptyAtBeginning(head,20);
    TraverseDoubly(head);
    return 0;
}