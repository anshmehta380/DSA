public class Circular_queue
{
    // Inititally both the pointers will be at -1 as the queue is empty
    int front =-1;
    int rear =-1;
    //size of the queue is 15
    int size = 15;
    //We are implementing queue using arr
   int arr[] = new int[size];
    public void push(int x)
    {
        //suppose size is 20 and your indexing might go from 0-19
        //therefore if REAR==19 than rear is pointing at the last most node and no space is left
        if(rear==size-1){
            System.out.println("Queue is not able to perform push operation it's empty");
            return;
        }
        if(isFull())
            System.out.println("QUEUE IS FULL");
            // the formula will give you front
        rear = (rear+1)%size;
        // now at arr[rear] insert data
        arr[rear]=x;
        //check the front pointer in case if you are inserting the first most node
        if(front==-1)
            front++;
    }
    public void pop(){
        //check for underflow and if front pointer exceeds the rear pointer
        // But how will Front be more than rear?
        // if you popped the last most element the front will be increased and point next location after rear
        if(front==-1 || front>rear){
            System.out.println("Queue is unable to perform pop operation");
            return;
        }
        // and for that case if front and rear are at same position and your are popping the last most
        // element than set both the pointers to -1
        if(rear == front)
        {
            rear = front = -1;
        }
//        else
//            front = (front+1)%size;
        front++;
    }
    public int peek(){
        if(front==-1 || front>rear) {
            System.out.println("Queue is unable to perform pop operation");
            return -1;
        }
        return arr[front];
    }
    boolean isEmpty(){
        if(front==-1 || front>rear)
            return true;
        return false;
    }
    boolean isFull()
    {
    
        return (rear+1)%size == front;
    }
    public static void main(String[] args)
    {
        Circular_queue c = new Circular_queue();
        c.push(1);
        c.push(2);
        c.push(3);
        c.push(4);
        System.out.println(c.peek());
        c.pop();
        System.out.println(c.peek());
        c.pop();
        System.out.println(c.peek());
        c.pop();
        System.out.println(c.peek());
        c.push(5);
        c.push(6);
        c.pop();
        System.out.println(c.peek());
        c.pop();
        System.out.println(c.peek());
        if(c.isEmpty())
            System.out.println("Queue is empty");
    }
}
