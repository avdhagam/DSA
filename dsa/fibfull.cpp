#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// memoization
//  TC=O(N) SC=O(N)+O(N)
int f(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

// tabulation
// TC:O(N) SC:O(N) bc array
int f1(int n)
{
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// better solution without using array
// TC: O(N) SC: O(1)
int f2(int n)
{
    int prev2 = 0;
    int prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main()
{
    cout << "enter n value";
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp) << " ";
    cout << f1(n) << " ";
    cout << f2(n) << " ";
}