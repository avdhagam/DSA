#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

vector<int>::iterator lowerbound(vector<int> v, int target)
{
    int l = 0;
    int r = v.size() - 1;
    int ans = v.size();
    while (l <= r)
    {
        int mid = l + ((r - l) / 2);
        if (v[mid] >= target)
        {
            ans = mid;
            r = mid - 1;
        }

        else if (v[mid] < target)
        {
            l = mid + 1;
        }
    }
    if (ans == v.size())
    {
        return v.end();
    }
    else
    {
        return v.begin() + ans;
    }
}

int main()
{
    vector<int> v = {1, 3, 5, 6};
    auto res = lowerbound(v, 5);
    if (res != v.end())
    {
        cout << distance(v.begin(), res);
    }
    else
    {
        cout << "lower bound doesnt exist" << endl;
    }
}