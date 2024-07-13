#include <stdio.h>
#include <iostream>
using namespace std;
#include <stack>

stack<int> SortStack(stack<int> &input)
{
    stack<int> temp;
    while (!input.empty())
    {
        int curr = input.top();
        input.pop();
        while (!temp.empty() && temp.top() < curr)
        {
            int r = temp.top();
            temp.pop();
            input.push(r);
        }
        temp.push(curr);
    }
    return temp;
}

int main()
{
    stack<int> s;
    s.push(6);
    s.push(4);
    s.push(7);
    s.push(2);
    s.push(3);
    stack<int> ans = SortStack(s);
    stack<int> temp;
    while (!ans.empty())
    {
        int top = ans.top();
        ans.pop();
        cout << top << endl;
        temp.push(top);
    }
}