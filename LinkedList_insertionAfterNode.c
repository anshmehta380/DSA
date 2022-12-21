#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverseLinkedList(struct node *head)
{
    struct node *p;
    p = head;
    while(p!=NULL)
    {
        printf("\nYour data is %d",p->data);
        p = p->next;
    }
}
struct node *afterNode(struct node *head,int index,int val)
{
    struct node *p = head;
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = val;
    int i = 1;
    while(i!=index)
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

    first->data = 11;
    first->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = NULL;
    // traverseLinkedList(first);
    first = afterNode(first,2,35);
    traverseLinkedList(first);
    return 0;
}