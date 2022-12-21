#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int r;
    int f;
    int*arr;
};

// int isEmpty(struct struct_class_name pointer)
int isEmpty(struct queue *q)
{
    if(q->r==-1 && q->f==-1 || q->f > q->r)
    //return true
    return 1;
    else
    // or false
    return 0;
}
int isFull(struct queue *q)
{
    if(q->r == q->size-1)
    return 1;
    else
    return 0;
}
void enqueue(struct queue *q,int val)
{
    if(isFull(q))
    {
        printf("The queue is full");
    }
    else{
        q->r++; 
        q->arr[q->r]=val;
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is empty");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    // q is the object we can access the structure queue
   struct queue q;
   q.size=100;
   q.f = q.r = -1;
   // malloc(size*type);
   // for example size = 100 and type is int therefore malloc will allocate total of 400bytes of memeory.
   q.arr = (int*) malloc(q.size*sizeof(int));
   // enqueue(adrress of q because it is taking a pointer as argument so it will point at it's address, value)
   enqueue(&q, 10);
   enqueue(&q, 12);
   printf("Dequeing the element %d", dequeue(&q));
   printf("Dequeing the element %d", dequeue(&q));
    if(isEmpty(&q))
        printf("Queue is empty");
    if(isFull(&q))
        printf("queue is full");
    return 0;
} 