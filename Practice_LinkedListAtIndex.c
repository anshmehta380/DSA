#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *insertAtIndex(struct node *first,int index,int val)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p = first;
    int i =0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }  
    ptr->data = val;
    ptr->next=p->next;
    p->next = ptr;
    return first;

};
void TraverseLinkedList(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Your element is: %d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *first;
    struct node *second;
    struct node *third;
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    first->data=10;
    first->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;
    first = insertAtIndex(first,1,1);
    TraverseLinkedList(first);
    return 0;
}