#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void pushzeros(vector<int> &arr, int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
}

int main()
{
    vector<int> nums = {1, 0, 3, 2, 0, 0, 1};
    pushzeros(nums, nums.size());
    for (auto i : nums)
    {
        cout << i << " ";
    }
}