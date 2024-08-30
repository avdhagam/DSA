class Solution
{
public:
    int f(int ind, vector<int> nums)
    {
        if (ind == 0)
            return nums[ind];
        int pick = nums[i];
        if (ind > 1)
        {
            pick = f(ind - 2, nums) + nums[ind];
        }
        int notpick = f(ind - 1, nums) + 0;
        return max(pick, notpick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        return f(n - 1, nums);
    }
};