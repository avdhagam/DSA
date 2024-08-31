bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= sum)
    {
        dp[0][arr[0]] = true;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= sum; target++)
        {
            bool pick = false;
            if (target - arr[ind] >= 0)
                pick = dp[ind - 1][target - arr[ind]];
            bool notpick = dp[ind - 1][target];
            dp[ind][target] = pick || notpick;
        }
    }

    return dp[n - 1][sum];
}