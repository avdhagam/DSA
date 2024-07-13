#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> twosum(int arr[], int n, int target)
{
    map<int, int> mp;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(target - arr[i]) != mp.end())
        {
            res.push_back(mp[target - arr[i]]); // returns the index of the value found
            res.push_back(i);
            return res;
        }
        else
        {
            mp[arr[i]] = i;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = (sizeof(arr) / sizeof(arr[0]));
    vector<int> result = (twosum(arr, n, 11));
    if (!result.empty())
    {
        cout << "indices are :" << endl;
        for (int idx : result)
        {
            cout << idx << endl;
        }
    }
    else
    {
        cout << "no pair found" << endl;
    }
}