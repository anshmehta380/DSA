#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

// Check Precedence
int prec(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else{
        return -1;
    }
}
string infixToPostfix(string s)
{ 
    stack<int>st;
    string res;
    for(int i=0;i<s.length();i++)
    {
        // For Operands
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
            // Print in the string
            res+=s[i];
        }
        else if(s[i]=='(')
        {
            // if opening bracket than push it in the stack
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            // if closing bracket then, while the stack is not empty and until it
            //  finds a opening bracket print every element in the string a keep poping each of them

            // NOTE:- You dont have to print opening or closing bracket into string.
            while(!st.empty() && st.top()!='(')
            {   
                res+=st.top();
                st.pop();
            }
            // if the stack is not empty then pop the opening bracket
            if(!st.empty())
            {
                st.pop();
            }
        }
        // For Operator
        else
        {
            // if the precedence value of the operator of top is higher than the value to be inserted
            // then print and pop the last operator and push the value that was meant to be inserted
            while(!st.empty() && prec(st.top())>prec(s[i]))
            {
                res+=st.top();
                st.pop();
            } 
            st.push(s[i]);
        }
    }
    // Print all the left elements in the string
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    return res;
}
int main()
{
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}