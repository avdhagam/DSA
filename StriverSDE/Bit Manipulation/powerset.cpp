class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        int numbersub = 1 << n;
        for (int i = 0; i < numbersub; i++)
        {
            vector<int> sub;
            for (int j = 0; j < 3; j++)
            {
                if (((1 << j) & i) != 0)
                {
                    sub.push_back(nums[j]);
                }
            }
            ans.push_back(sub);
        }
        return ans;
    }
};