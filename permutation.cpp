#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void recurPermute(int index, vector<vector<int>> &ans, vector<int> &nums);

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    recurPermute(0, ans, nums);
    return ans;
}

void recurPermute(int index, vector<vector<int>> &ans, vector<int> &nums)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        recurPermute(index + 1, ans, nums);
        swap(nums[i], nums[index]);
    }
}

int main()
{
    vector<int> v = {1, 1, 3};
    vector<vector<int>> ans = permute(v);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}