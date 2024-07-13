#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void kadanesalgo(vector<int> &nums, vector<vector<int>> ans, vector<int> ds)
{
    int ans = INT_MIN;
    int cursum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cursum + nums[i] > 0)
        {
            cursum = cursum + nums[i];
            ds.push_back(nums[i]);
        }
        else
        {
            cursum = 0;
            ans.push_back(ds);
        }
        ans = max(ans, cursum);
    }
    return ans;
}

vector<vector<int>> kadanes(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    kadanesalgo(nums, ans, ds);
}
