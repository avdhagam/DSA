#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void findcombo(int index, int n, int k, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr);

vector<vector<int>> combosum3(int n, int k)
{
    vector<int> ds;
    vector<vector<int>> ans;
    vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    findcombo(0, n, k, ds, ans, candidates);
    return ans;
}

void findcombo(int index, int n, int k, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr)
{
    if (ds.size() == k)
    {
        if (n == 0)
        {
            ans.push_back(ds);
            return;
        }
    }
    for (int i = index; i < arr.size(); i++)
    {
        ds.push_back(arr[i]);
        findcombo(i + 1, n - arr[i], k, ds, ans, arr);
        ds.pop_back();
    }
}

int main()
{
    vector<vector<int>> ans = combosum3(7, 3);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}