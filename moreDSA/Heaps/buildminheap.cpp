#include <bits/stdc++.h>

void heapify(int n, vector<int> &arr, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(n, arr, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    for (int i = floor(n / 2) + 1; i >= 0; i--)
    {
        heapify(n, arr, i);
    }
    return arr;
}
