#include <iostream>
#include <stdio.h>
using namespace std;
#include <vector>

void printsubsequence(int index, vector<int> &ds, vector<int> arr, int n)
{
    if (index == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{ }";
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[index]);
    printsubsequence(index + 1, ds, arr, n);
    ds.pop_back();
    printsubsequence(index + 1, ds, arr, n);
}

int main()
{
    vector<int> arr = {3, 2, 1};
    vector<int> ds = {};
    printsubsequence(0, ds, arr, arr.size());
}
