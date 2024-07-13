#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int helper(int n, vector<int> &dp)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    if (n == 1)
    {
        return 0;
    }

    int ans2 = 1e9;
    int ans3 = 1e9;

    if (n < 1)
    {
        return 1e9;
    }
    int minusOne = 1 + helper(n - 1, dp);
    if (n % 2 == 0)
    {
        ans2 = 1 + helper(n / 2, dp);
    }
    if (n % 3 == 0)
    {
        ans3 = 1 + helper(n / 3, dp);
    }
    return dp[n] = min({ans2, ans3, minusOne});
}

int countstepstoone(int n)
{
    vector<int> dp(n + 1, -1);
    return helper(n, dp);
}

int main()
{
    cout << countstepstoone(2);
}