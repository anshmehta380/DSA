#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int*arr;
};
int isFull(struct queue *q)
{
    if(q->r == q->size-1)
    return 1;
    else
    return 0;
}
int isEmpty(struct queue *q)
{
    if(q->f==-1 && q->r==-1 || q->f > q->r)
    return 1;
    else
    return 0;
}
void enqueue(struct queue *q,int val)
{
    if(isFull(q)){
        printf("Queue is full!");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;
    }
}
int dequeue(struct queue *q)
{
    int a =-1;
    if(isEmpty(q)){ 
        printf("Queue is empty!");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct queue q;
    q.r = q.f = -1;
    q.size = 10;
    q.arr = (int*) malloc(q.size*sizeof(int));
    enqueue(&q, 10);
    enqueue(&q, 12);
    printf("Dequeing the element %d\n", dequeue(&q));
     printf("Dequeing the element %d\n", dequeue(&q));
    if(isFull(&q))
        printf("Queue is full\n");
    if(isEmpty(&q))
        printf("Queue is empty\n");

}