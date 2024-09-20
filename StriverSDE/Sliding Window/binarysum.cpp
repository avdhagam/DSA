class Solution
{
public:
    int f(vector<int> &nums, int goal)
    {
        int l = 0;
        int r = 0;
        int count = 0;
        long long sum = 0;
        while (r < nums.size())
        {
            sum += nums[r];
            while (sum > goal && l <= r)
            {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return f(nums, goal) - f(nums, goal - 1);
    }
};