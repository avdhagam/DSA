class Solution
{
public:
    int f(vector<int> &nums, int i, int jumps)
    {
        int mini = INT_MAX;
        if (i >= nums.size() - 2)
            return jumps;
        for (int j = 1; j < nums[i]; j++)
        {
            mini = min(mini, f(nums, i + j, jumps + 1));
        }
        return mini;
    }
    int jump(vector<int> &nums)
    {
        return f(nums, 0, 0);
    }
};