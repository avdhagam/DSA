#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <deque>

vector<int> maxslidingwindow(vector<int> nums, int k)
{
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() == (i - k))
        {
            dq.pop_front();
        }
        while (!dq.empty() && dq.back() < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i > k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = maxslidingwindow(nums, 3);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}