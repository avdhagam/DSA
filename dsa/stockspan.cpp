#include <stdio.h>
#include <iostream>
using namespace std;
#include <stack>
#include <vector>

void stockSpan(vector<int> a, int n)
{
    vector<int> ans;
    stack<int> st;
    st.push(0);
    ans.push_back(1);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && a[st.top()] <= a[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans.push_back(i + 1);
        }
        else
        {
            ans.push_back(i - st.top());
        }
        st.push(i);
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> a = {100, 80, 60, 70, 60, 75, 85};
    stockSpan(a, a.size());
}