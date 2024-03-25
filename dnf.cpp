#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void dnf(vector<int> &nums)
{
    int mid = 0;
    int low = 0;
    int high = nums.size() - 1;
    while (mid <= high)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
}

int main()
{
    vector<int> arr = {1, 0, 2, 1, 0, 0};
    dnf(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}