class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxInd = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxInd < i)
                return false;
            maxInd = max(maxInd, i + nums[i]);
        }
        return true;
    }
};