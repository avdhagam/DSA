#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

int recursive(int ind, vector<int> heights)
{
    if (ind == 0)
    {
        return 0;
    }
    int left = recursive(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = recursive(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);
    }
    return min(left, right);
}

/* 3 changes to be made to change a recursive code to memoization
1. add a dp array : dp[n-1]
2. return dp[ind]=min(left,right);
3. in the beginning add a condition: if(dp[ind]!=-1) return dp[ind];
*/

int memoization(int ind, vector<int> &heights, vector<int> &dp)
{
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    if (ind == 0)
    {
        return 0;
    }
    int left = memoization(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;

    if (ind > 1)
    {
        right = memoization(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    }

    return dp[ind] = min(left, right);
}

void frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    cout << recursive(n - 1, heights) << endl;
    cout << memoization(n - 1, heights, dp) << endl;
}

int main()
{
    vector<int>
        heights = {10, 20, 60, 30, 10};
    frogJump(5, heights);
}