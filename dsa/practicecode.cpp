#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void function(vector<int> &ds, vector<vector<int>> &ans, int freq[], vector<int> &nums)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq[i] != 1)
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            function(ds, ans, freq, nums);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()] = {0};
    function(ds, ans, freq, nums);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j;
        }
        cout << endl;
    }
}