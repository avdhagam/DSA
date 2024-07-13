#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

void heapify(vector<int> &heap, int idx, int size())
{
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int largest = idx;
    if (l < heap.size() && heap[largest] < heap[l])
    {
        largest = l;
    }
    if (r < heap.size() && heap[largest] < heap[r])
    {
        largest = r;
    }
    if (largest != idx)
    {
        swap(heap[largest], heap[idx]);
        heapify(heap, largest, heap.size());
    }
}




