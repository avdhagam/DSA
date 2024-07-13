#include <stdio.h>
using namespace std;
#include <iostream>
#include <vector>

int kadanesalgo(vector<int> &nums)
{
    int cursum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cursum + nums[i] > 0)
        {
            cursum = cursum + nums[i];
        }
        else
        {
            cursum = 0;
        }
        ans = max(ans, cursum);
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 7, -2, 5, 16, 11};
    cout << kadanesalgo(v);
}