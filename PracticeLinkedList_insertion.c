#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverseLinkedList(struct node *ptr)
{
    while(ptr!=NULL)
    {
    printf("Your element is %d\n",ptr->data);
    ptr = ptr->next;
    }
}
struct node *insertAtFront(struct node *head,int val)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->next=head;
    p->data=val;
    return p;
};
void searchLinkedList(struct node *ptr,int val)
{   
    int count= 0;
    int f=0;
    while(ptr->next!=NULL)
    {
        if(ptr->data==val)
        {
            f=1;
            break;
        }
        ptr = ptr->next;
        count++;
    }
   if(f==1)
   {
    printf("Data is at node %d\n",count);
   }
   else{
    printf("Data not found!!!");
   }
};
struct node *insertAtIndex(struct node *head,int index,int val)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node*));
    struct node *p = head;
    int i =0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = val;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;
    traverseLinkedList(head);
    head = insertAtFront(head,1);
    traverseLinkedList(head);
    searchLinkedList(head,10);
    head = insertAtIndex(head,1,2);
    traverseLinkedList(head);
    return 0;
}
