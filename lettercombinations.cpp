#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void findcombo(int index, string digits, string ds, vector<string> &ans, string mapping[]);

vector<string> lettercombinations(string digits)
{
    vector<string> ans;
    string ds = "";
    if (digits == "")
    {
        return ans; // empty vector
    }
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    findcombo(0, digits, ds, ans, mapping);
    return ans;
}

void findcombo(int index, string digits, string ds, vector<string> &ans, string mapping[])
{
    if (index >= digits.length())
    {
        ans.push_back(ds);
        return;
    }
    int number = digits[index] - '0';
    string value = mapping[number];
    for (int i = 0; i < value.length(); i++)
    {
        ds.push_back(value[i]);
        findcombo(index + 1, digits, ds, ans, mapping);
        ds.pop_back();
    }
}

int main()
{
    vector<string> ans = lettercombinations("23");
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}