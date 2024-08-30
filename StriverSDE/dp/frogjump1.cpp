#include <bits/stdc++.h>
int f(int ind, vector<int> &heights)
{
    if (ind == 0)
        return 0;

    int left = f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind >= 2)
    {
        right = f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);
    }
    return min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return f(n - 1, heights);
}