#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<string>> groupanagram(vector<string> &arr)
{
    vector<vector<string>> ans;
    map<string, vector<string>> mp;
    for (auto ele : arr)
    {
        string temp = ele;
        sort(temp.begin(), temp.end());
        if (mp.find(temp) != mp.end())
        {
            mp[temp].push_back(ele);
        }
        else
        {
            mp[temp] = {ele};
        }
    }
    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    vector<string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupanagram(arr);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << ",";
        }
    }
}
