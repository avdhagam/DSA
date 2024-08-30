class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int pick = INT_MIN;
            if (i > 1)
            {
                pick = dp[i - 2] + nums[i];
            }
            int notpick = dp[i - 1] + 0;
            dp[i] = max(pick, notpick);
        }
        return dp[n - 1];
    }
};