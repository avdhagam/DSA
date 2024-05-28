#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

vector<int> spellsandpotions(vector<int> &spells, vector<int> &potions, long long success)
{
    sort(potions.begin(), potions.end());
    vector<int> answervector;
    for (auto i : spells)
    {
        int ans = 0;
        int l = 0;
        int r = potions.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            long long mul = i * potions[mid];

            if (mul >= success)
            {
                ans = mid;
                r = mid - 1;
                cout << "ans is " << ans << endl;
            }
            else if (mul < success)
            {
                l = mid + 1;
            }
        }
        if (ans == 0 && l == potions.size() - 1)
        {
            answervector.push_back(0);
        }
        else if (ans == 0 && l == 0)
        {
            answervector.push_back(potions.size());
        }

        else
        {
            answervector.push_back(potions.size() - ans);
        }
    }
    return answervector;
}

int main()
{
    vector<int> spells = {15, 8, 19};
    vector<int> potions = {38, 36, 23};
    int success = 328;
    vector<int> v = spellsandpotions(spells, potions, success);
    for (auto i : v)
    {
        cout << i << " ";
    }
}