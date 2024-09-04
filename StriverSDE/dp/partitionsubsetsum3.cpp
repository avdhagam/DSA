#include <numeric>

bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int s = accumulate(arr.begin(), arr.end(), 0);
    if (s % 2 == 1)
        return false;
    else
    {
        vector<vector<bool>> dp(n, vector<bool>((s / 2) + 1, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        if (arr[0] == s / 2)
        {
            dp[0][arr[0]] = true;
        }
        for (int i = 1; i < n; i++)
        {
            for (int tar = 1; tar <= s / 2; tar++)
            {
                bool taken = false;
                if (arr[i] <= tar)
                {
                    taken = dp[i - 1][tar - arr[i]];
                }
                bool nottaken = dp[i - 1][tar];
                dp[i][tar] = taken || nottaken;
            }
        }

        return dp[n - 1][s / 2];
    }
}
