class Solution
{
public:
    int f(int ind, vector<int> nums, vector<int> &dp)
    {
        if (ind == 0)
            return nums[ind];
        if (dp[ind] != -1)
            return dp[ind];
        int pick = nums[i];
        if (ind > 1)
        {
            pick = f(ind - 2, nums, dp) + nums[ind];
        }
        int notpick = f(ind - 1, nums, dp) + 0;
        return dp[ind] = max(pick, notpick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1, nums, dp);
    }
};