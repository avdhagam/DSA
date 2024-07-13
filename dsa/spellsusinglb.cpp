#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

vector<int> spellsandpotions(vector<int> spells, vector<int> potions, long long success)
{
    sort(potions.begin(), potions.end());
    vector<int> ans;
    for (int i : spells)
    {
        int position = lower_bound(potions.begin(), potions.end(), ceil(double(success) / i)) - potions.begin();
        ans.push_back(potions.size() - position);
    }
    return ans;
}

int main()
{
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    int success = 7;
    vector<int> ans = spellsandpotions(spells, potions, success);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}