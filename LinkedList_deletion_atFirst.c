#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};

void TraverseLinkedList(struct node *head)
{
    while(head!=NULL)
    {
        printf("\nYour elements are %d",head->data);
        head = head->next;
    }
}
struct node *deleteAtfirst(struct node *head)
{
    struct node *p = head;
    if(head->next==NULL)
    {
        printf("No Link List exists.");
    }
    head = p->next;
    free(p);
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth; 

    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node*) malloc(sizeof(struct node));

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = NULL;

    printf("\nBefore Deleting");
    TraverseLinkedList(head);
    printf("\nAfter Deleting");
    head = deleteAtfirst(head);
    TraverseLinkedList(head);

    return 0;
}