#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int SelfPrefixEvaluation(string s)
{
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            // Suppose prefix is -+739/3-24
            // here we will traverse the string from last
            // first 4 is pushed in the stack
            // 2 is pushed in the stack above 4
            // the last inserted operand is always op1 in prefix because it will perform the operation with the value that is entered before it is pushed
            int op1=st.top();       //Storing 2 in op1
            st.pop();               // Popped 2
            int op2=st.top();       // top is pointing at 4, So we stored 4 in op2 
            st.pop();               // 4 is popped

            // now st.top() is pointing at a Operator
            // it will perform the operator functions and will push the result value in the stack
            switch(s[i])
            {
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
            }
        }
    }
    // The last value that is available in the stack is the result of all the operations
    //  that are performed and the st.top() value is returned to the function call;
    return st.top();
}
int main()
{
    cout<<SelfPrefixEvaluation("-+7*45+20")<<endl;
    return 0;
}