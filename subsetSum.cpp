#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void fun(int index, int sum, vector<int> &ans, int N, vector<int> &arr)
{
    if (index == N)
    {
        ans.push_back(sum);
        return;
    }
    fun(index + 1, sum + arr[index], ans, N, arr);
    fun(index + 1, sum, ans, N, arr);
}

vector<int> subsetSum(vector<int> arr, int N)
{
    vector<int> ans;
    fun(0, 0, ans, N, arr);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> ans = subsetSum(arr, 5);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}