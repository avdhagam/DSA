#include <stdio.h>
using namespace std;
#include <vector>
#include <iostream>

//recursion
int f1(int index, int prev, vector<int> &arr, int n)
{
    if (index == n)
    {
        return 0;
    }
    int len = 0 + f1(index + 1, prev, arr, n);
    if (prev == -1 || arr[prev] < arr[index])
    {
        len = 1 + f1(index + 1, index, arr, n);
    }
    return len;
}


int longestincreasingsubsequence(vector<int> arr, int n)
{
    return f1(0, -1, arr, n);
}
int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << longestincreasingsubsequence(arr, arr.size());
}