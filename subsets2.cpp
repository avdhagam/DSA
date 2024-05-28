#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findsubsets(0, ans, ds, nums);
    return ans;
}

void findsubsets(int index, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums)
{
    if (index == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    if (index == 0 || nums[index] == nums[index - 1])
    {
        ds.push_back(nums[index]);
        findsubsets(index + 1, ans, ds, nums);
        ds.pop_back();
    }
    findsubsets(index + 1, ans, ds, nums);
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2};
    vector<vector<int>> ans = subsets(nums);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}