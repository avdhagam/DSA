#include <stdio.h>
#include <iostream>
using namespace std;
#include <stack>

bool isBalanced(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
                return false;
            char c = st.top();
            st.pop();
            if ((c == '{' && s[i] == '}') || (c == '(' && s[i] == ')') || (c == '[' && s[i] == ']'))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string s = "}";
    if (isBalanced(s))
    {
        cout << "Balanced";
    }
    else
    {
        cout << " Not Balanced";
    }
}