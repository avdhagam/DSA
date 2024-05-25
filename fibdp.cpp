#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

int f(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

int main()
{
    int n;
    cout << "enter n value" << endl;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp);
    return 0;
}