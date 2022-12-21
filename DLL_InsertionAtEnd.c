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
struct node *insertAtEnd(struct node *head,int val)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    temp->prev = p;
    temp->data = val;
    p->next = temp;
    return head;
    
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    head->prev=NULL;
    head->data=10;
    head->next=second;
    second->prev=head;
    second->data=20;
    second->next=NULL;
    head = insertAtEnd(head,30);
    TraverseDoubly(head);
    return 0;
}