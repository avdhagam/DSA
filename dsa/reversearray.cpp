#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> reversearray(vector<int> &nums, int low, int high)
{
    while (low < high)
    {
        swap(nums[low], nums[high]);
        low++;
        high--;
    }
    return nums;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    auto result = reversearray(arr, 0, n - 1);
    for (auto i : result)
    {
        cout << i << endl;
    }
}