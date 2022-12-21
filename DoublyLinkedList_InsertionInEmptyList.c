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
        printf("Element is: %d",p->data);
        p = p->next;
    }
}
struct node *insertInEmpty(struct node *head,int val)
{
struct node *temp = (struct node*)malloc(sizeof(struct node));
temp->prev=NULL;
temp->data=val;
temp->next=NULL;
head = temp;
return head;
}
int main()
{
    struct node *head = NULL;
    head = insertInEmpty(head,10);
    TraverseDoubly(head);
    return 0;
}