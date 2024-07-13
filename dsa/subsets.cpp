#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void findsubsets(int index, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans);

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findsubsets(0, nums, ds, ans);
    return ans;
}

void findsubsets(int index, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    if (index == 0)
    {
        cout << "{ }" << endl;
    }
    ds.push_back(nums[index]);
    findsubsets(index + 1, nums, ds, ans);
    ds.pop_back();
    findsubsets(index + 1, nums, ds, ans);
}

int main()
{
    vector<int> nums = {1, 2, 3};
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