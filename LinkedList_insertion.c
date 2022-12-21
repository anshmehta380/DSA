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
        printf("Element is %d\n",ptr->data);
        ptr = ptr->next;
    }
}

// Takes head node and data as parameter
struct node *insertAtFirst(struct node*head,int val)
{
    // Creating a new node ptr
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    // New node data will be taken from the parameter
    ptr->data=val;
    // The pointer of the ptr node will point at head
    ptr->next=head;
    return ptr;
};

struct node *insertAtIndex(struct node *head,int val,int index)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = val;
    return head;

};
struct node *insertAtEnd(struct node *head,int val)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->data = val;
    return head;
};
struct node *insertAfterNode(struct node *head, struct node *PrevNode,int val)
{
struct node *ptr = (struct node*)malloc(sizeof(struct node*));
ptr->next = PrevNode->next;
PrevNode->next = ptr;
ptr->data = val;
};
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=NULL;

    printf("Before Insertion at first: \n");
    traverseLinkedList(head);
    head = insertAtFirst(head,1);
    printf("After Insertion at first: \n");
    traverseLinkedList(head);
    printf("\n\n");
    printf("Before Insertion at Index: \n");
    traverseLinkedList(head);
    head = insertAtIndex(head,1,3);
    printf("After Insertion at Index: \n");
    traverseLinkedList(head);

    head = insertAtEnd(head,100);
    traverseLinkedList(head);

    head = insertAfterNode(head,second,111);
    traverseLinkedList(head);
    return 0;
}