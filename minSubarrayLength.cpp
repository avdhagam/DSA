#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <limits>

int minSubarrayLength(int target, vector<int> &nums)
{
    int minLenWindow = INT_MAX;
    int cursum = 0;

    int high = 0;
    int low = 0;

    while (high < nums.size())
    {
        cursum += nums[high];
        high++;

        while (cursum > target)
        {
            int currLenWindow = high - low;
            minLenWindow = min(minLenWindow, currLenWindow);

            cursum -= nums[low];
            low++;
        }
    }
    return minLenWindow == INT_MAX ? 0 : minLenWindow;
}

int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubarrayLength(7, nums);
}