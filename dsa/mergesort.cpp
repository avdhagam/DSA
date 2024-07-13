#include <iostream>
#include <stdio.h>
using namespace std;
#include <vector>
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int ptr1 = low;
    int ptr2 = mid;
    while (ptr1 < mid && ptr2 < high)
    {
        if (arr[ptr1] < arr[ptr2])
        {
            temp.push_back(arr[ptr1]);
            ptr1++;
        }
        else
        {
            temp.push_back(arr[ptr2]);
            ptr2++;
        }
    }
    while (ptr1 < mid)
    {
        temp.push_back(arr[ptr1]);
        ptr1++;
    }
    while (ptr2 < high)
    {
        temp.push_back(arr[ptr2]);
        ptr2++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[low + i] = temp[i];
    }
}

void mergesort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    vector<int> v = {10, 5, 6, 1, 2, 15, 30};
    mergesort(v, 0, v.size() - 1);
    for (auto i : v)
    {
        cout << i << " ";
    }
}
