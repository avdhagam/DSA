#include <iostream>
#include <stdio.h>
using namespace std;
#include <vector>

bool isPalindrome(string s, int start, int end);
void func(int index, vector<vector<string>> &ans, vector<string> &ds, string s);

vector<vector<string>> palindromepartitioning(string s)
{
    vector<vector<string>> ans;
    vector<string> ds;
    func(0, ans, ds, s);
    return ans;
}
void func(int index, vector<vector<string>> &ans, vector<string> &ds, string s)
{
    if (index == s.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            ds.push_back(s.substr(index, i - index + 1));
            func(i + 1, ans, ds, s);
            ds.pop_back();
        }
    }
}

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<string>> ans = palindromepartitioning("avani");
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}