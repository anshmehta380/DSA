public class Queue
{
    int front;
    int back;
    int arr[];
    int size =20;
    Queue()
    {
        arr= new int[size];
        front =-1;
        back =-1;
    }
    void push(int x)
    {
        if(back==size-1)
        {
            System.out.println("Queue is empty in push function");
            return;
        }
//        rear = (rear+1)%size;
        back++;
        arr[back]=x;
        if(front==-1)
            front++;
    }
    void pop()
    {
        if(front==-1 || front>back) {
            System.out.println("Bhadve back -1 hai ya front aage chala gaya");
            return;
        }
//        if(rear == front){
//            rear = front = -1;
//        }
        front++;
    }
    int peek()
    {
        if(front==-1 || front>back)
        {
            System.out.println("peek nathi thato chodu");
            return -1;
        }
        return arr[front];
    }
    boolean empty()
    {
        if(front==-1 || front>back)
        {
            System.out.println("Queue khali ho gayi bhadve");
            return true;
        }
        return false;
    }
//    boolean isFull()
//    {
//        return (rear+1)%size == front;
//    }
    public static void main(String[] args)
    {
        Queue e = new Queue();
        e.push(1);
        e.push(2);
        e.push(3);
        e.push(4);

        System.out.println(e.peek());
        e.pop();
        System.out.println(e.peek());
        e.pop();
        System.out.println(e.peek());
        e.pop();
        System.out.println(e.peek());
        e.pop();
        if(e.empty())
            System.out.println("Bhavde kyu khali h");
    }
}
