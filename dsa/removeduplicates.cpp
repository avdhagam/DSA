#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int removeduplicates(vector<int> &arr, int n)
{
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[res - 1] != arr[i])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 4, 5};
    auto newsize = removeduplicates(nums, nums.size());
    for (int i = 0; i < newsize; i++)
    {
        cout << nums[i] << endl;
    }
}
