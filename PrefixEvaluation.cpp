#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int prefixEvaluation(string s)
{
    stack<int> st;
    // length()-1 why? String starts from 1 index but we know memory starts allocation from 0th index which will be considered as 1
    // so 0 to 9 = 10 elements (because 0 is included)
    // therfore the index is started from 0 so we will goto N th - 1 index to reach the last value
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
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
                    st.push(op1^op2);
                    break;
            }
        
        }
    }
    return st.top();
}
int main()
{
    cout<<prefixEvaluation("-+7*45+20");
    return 0;
}