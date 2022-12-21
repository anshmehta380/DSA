#include<iostream>
using namespace std;
class stack{
    // Declare Variable's here so you can access them all across your class
    int* arr;
    int top;
    int n;
    // Make it all public
    public:
    // Constructor that will instansiate the variable
    stack()
    {
    n=100;
    arr = new int[n];
    //in array of 100 top is at -1 which means there is nothing in the array
    top=-1;
    }
    // PUSH OPERATION
    void push(int x){
        // if top == 100-1 then it will say stack is full
        if(top==n-1){
            cout<<"Your stack is full: "<<endl;
        }
        //increment the top from "-1" to "0" which is the first index of array -For example purpose Only
        top++;
        // arr[0]=user_passed_value;
        arr[top]=x;
    }
    void pop(){
        // Condition is used to check wheter the stack is empty or not
        if(top==-1){
            cout<<"Stack is empty so you can't PoP: "<<endl;
        }
        // Decrement the value from "0" to "-1" -Just for example
        top--;
    }
    int Top(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        // It will return the value that the top variable is pointing 
        return arr[top];
    }
    bool empty(){
        //if stack is empty then it will print the following line.
        if(top==-1){
            cout<<"Stack is empty!!"<<endl;
        }
    }
};
int main(){
    // Created obect of stack class.
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    // Use cout in case if the stack is not empty the variable will not print
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.empty()<<endl;
    return 0;
}