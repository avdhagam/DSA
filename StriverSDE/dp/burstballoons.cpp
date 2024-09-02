#include <bits/stdc++.h>
int f(int i, int j, vector<int> &a)
{
    if (i > j)
        return 0;
    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = (a[i - 1] * a[ind] * a[j + 1]) + f(i, ind - 1, a) + f(ind + 1, j, a);
        maxi = max(cost, maxi);
    }
    return maxi;
}

int maxCoins(vector<int> &a)
{
    // Write your code here.
    a.push_back(1);
    a.insert(a.begin(), 1);
    return f(1, a.size() - 2, a);
}