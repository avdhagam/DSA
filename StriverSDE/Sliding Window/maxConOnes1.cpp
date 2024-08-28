class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxlen = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int zeroes = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                {
                    zeroes++;
                }
                if (zeroes <= k)
                {
                    int len = j - i + 1;
                    maxlen = max(maxlen, len);
                }
                else if (zeroes > k)
                    break;
            }
        }
        return maxlen;
    }
};