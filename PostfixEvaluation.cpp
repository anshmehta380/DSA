#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int postfixEvaluation(string s)
{
    stack<int> st;
    // we will traverse the string from starting index
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            // To convert a character that is integer simply - 0 from it.
            // why? - because the ASCII value of the character - the ASCII value of 0 will be the integer 
            st.push(s[i]-'0');
        }
        else{
            // Suppose that postfix is 46+29-9*
            // 4 will be stored in stack first then 6 
            // therefore the value 6 is at top of the stack but in above postfix expression it is the second operand
            // that's why it is stored in "op2" - Do not get confused here
            int op2=st.top();   // 6 is stored in op2
            st.pop();           // 6 is popped now top() has 4 in the stack
            int op1=st.top();   // stored 4 in op1
            st.pop();           // popped 4

            // Here whatever the operator will be it will perform the operation and will push the answer in the stack.
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
    return st.top();
}
int main()
{
    cout<<postfixEvaluation("46+2/5*7+")<<endl;
    return 0;
}