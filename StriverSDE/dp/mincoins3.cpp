

int minimumElements(vector<int> &arr, int x)
{
    // Write your code here.
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int tar = 0; tar <= x; tar++)
    {
        if (tar % arr[0] == 0)
        {
            dp[0][tar] = tar / arr[0];
        }
        else
            dp[0][tar] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= x; tar++)
        {

            int notpick = dp[ind - 1][tar];
            int pick = 1e9;
            if (arr[ind] <= tar)
            {
                pick = 1 + dp[ind][tar - arr[ind]];
            }
            dp[ind][tar] = min(pick, notpick);
        }
    }

    int ans = dp[n - 1][x];
    if (ans >= 1e9)
        return -1;
    return ans;
}