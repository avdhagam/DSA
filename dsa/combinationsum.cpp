#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void combinationsum(int index, int target, vector<vector<int>> &ans, vector<int> arr, vector<int> &ds)
{
    if (index == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (arr[index] < target)
    {
        ds.push_back(arr[index]);
        combinationsum(index, target - arr[index], ans, arr, ds); // pick
        ds.pop_back();
    }
    combinationsum(index + 1, target, ans, arr, ds); // not pick
}

int main()
{
    vector<vector<int>> ans;
    vector<int> arr = {2, 3, 6, 7};
    vector<int> ds;
    combinationsum(0, 7, ans, arr, ds);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}