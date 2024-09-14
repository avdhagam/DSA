#include <bits/stdc++.h>
int f(int ind, int tar, vector<int> &arr)
{
    if (ind == 0)
    {
        if (tar % arr[0] == 0)
            return tar / arr[0];
        return INT_MAX;
    }

    int notpick = f(ind - 1, tar, arr);
    int pick = INT_MAX;
    if (arr[ind] <= tar)
    {
        pick = 1 + f(ind, tar - arr[ind], arr);
    }

    return min(pick, notpick);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    int ans = f(n - 1, x, num);
    if (ans >= INT_MAX)
        return -1;
    return ans;
}