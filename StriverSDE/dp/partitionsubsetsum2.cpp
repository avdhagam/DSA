#include <numeric>

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return arr[ind] == target;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool taken = false;
    if (arr[ind] <= target)
    {
        taken = f(ind - 1, target - arr[ind], arr, dp);
    }
    bool nottaken = f(ind - 1, target, arr, dp);
    return dp[ind][target] = taken || nottaken;
}

bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int s = accumulate(arr.begin(), arr.end(), 0);
    if (s % 2 == 1)
        return false;
    else
    {
        vector<vector<int>> dp(n, vector<int>((s / 2) + 1, -1));
        return f(n - 1, s / 2, arr, dp);
    }
}
