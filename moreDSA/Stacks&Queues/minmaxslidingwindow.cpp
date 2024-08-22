#include <bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n)
{
    // Write your code here.
    vector<int> left(n, -1);
    vector<int> right(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            left[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            right[i] = st.top();
        st.push(i);
    }

    vector<int> ans(n, INT_MIN);
    for (int i = 0; i < n; i++)
    {
        int len = right[i] - left[i] - 1;
        ans[len - 1] = max(a[i], ans[len - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}