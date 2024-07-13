#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void bt(int open, int close, string str, vector<string> &ans, int n);

vector<string> generateParentheses(int n)
{
    vector<string> ans;
    string str = " ";
    int open = 0;
    int close = 0;
    bt(0, 0, str, ans, n);
    return ans;
}

void bt(int open, int close, string str, vector<string> &ans, int n)
{
    if (open == close && open == n)
    {
        ans.push_back(str);
        return;
    }
    if (open < n)
    {
        str += "(";
        bt(open + 1, close, str, ans, n);
        str.pop_back();
    }
    if (close < open)
    {
        str += ")";
        bt(open, close + 1, str, ans, n);
        str.pop_back();
    }
}
int main()
{
    vector<string> ans = generateParentheses(3);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}