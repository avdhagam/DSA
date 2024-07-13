#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

int sqrt(int target)
{
    vector<int> v;
    for (int i = 0; i < target; i++)
    {
        v.push_back(i);
    }
    int l = 0;
    int r = v.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] * v[mid] == target)
        {
            return v[mid];
        }
        else if (v[mid] * v[mid] < target)
        {
            l = mid + 1;
        }
        else if (v[mid] * v[mid] > target)
        {
            r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    cout << sqrt(25) << endl;
}