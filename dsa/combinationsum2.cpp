#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void findcombo(int index, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &ans);

vector<vector<int>> combosum2(vector<int> &candidates, int target)
{
    vector<int> ds;
    vector<vector<int>> ans;
    findcombo(0, candidates, target, ds, ans);
    return ans;
}

void findcombo(int index, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        ds.push_back(candidates[i]);
        findcombo(i + 1, candidates, target - candidates[i], ds, ans);
        ds.pop_back();
    }
}

int main()
{
    vector<int> candidates = {1, 1, 1, 2, 2};
    vector<vector<int>> ans = combosum2(candidates, 4);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
