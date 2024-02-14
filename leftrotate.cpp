#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &nums, int low, int high)
{
    while (low < high)
    {
        swap(nums[low], nums[high]);
        low++;
        high--;
    }
}

vector<int> leftrotate(vector<int> &nums, int n, int k)
{
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
    reverse(nums, 0, n - 1);
    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k;
    cout << "Enter the number of places you want to left rotate by: " << endl;
    cin >> k;
    vector<int> result = leftrotate(nums, nums.size(), k);
    for (auto i : result)
    {
        cout << i << endl;
    }
}