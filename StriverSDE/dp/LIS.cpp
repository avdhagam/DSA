class Solution
{
public:
    int f1(int index, int prev, vector<int> &arr, int n, vector<vector<int>> &dp)
    {
        if (index == n)
        {
            return 0;
        }

        if (dp[index][prev + 1] != -1)
        {
            return dp[index][prev + 1];
        }

        int len = 0 + f1(index + 1, prev, arr, n, dp);
        if (prev == -1 || arr[index] > arr[prev])
        {
            len = max(len, 1 + f1(index + 1, index, arr, n, dp));
        }
        return dp[index][prev + 1] = len;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return f1(0, -1, nums, nums.size(), dp);
    }
};