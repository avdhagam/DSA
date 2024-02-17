#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

int binarysearch(vector<int> v, int target)
{
    int l = 0;
    int r = v.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] == target)
        {
            return mid;
        }
        else if (v[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << binarysearch(v, 5);
}