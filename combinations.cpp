#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void findcombo(int index, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr, int k);

vector<vector<int>> combination(int n, int k)
{
    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }
    vector<int> ds;
    vector<vector<int>> ans;
    findcombo(0, ds, ans, arr, k);
    return ans;
}

void findcombo(int index, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr, int k)
{
    if (k == ds.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        ds.push_back(arr[i]);
        findcombo(i + 1, ds, ans, arr, k);
        ds.pop_back();
    }
}

int main()
{
    vector<vector<int>> ans = combination(4, 2);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}