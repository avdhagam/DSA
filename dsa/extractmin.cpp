#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

class minheap
{
public:
    vector<int> arr;
    int size;
    minheap()
    {
        this->size = 0;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    void insert(int x)
    {
        size++;
        arr.push_back(x);
        for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int i)
    {
        int lt = left(i);
        int rt = right(i);
        int smallest = i;
        if (lt < size && arr[i] > arr[lt])
        {
            smallest = lt;
        }
        if (rt < size && arr[i] > arr[rt])
        {
            smallest = rt;
        }
        if (smallest != i)
        {
            swap(arr[smallest], arr[i]);
            heapify(smallest);
        }
    }

    int extractmin()
    {
        if (size == 0)
        {
            return INT_MAX;
        }
        if (size == 1)
        {
            size--;
            return arr[size - 1];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        heapify(0);
        return arr[size];
    }
};

int main()
{
    minheap heap;
    heap.insert(1);
    heap.insert(30);
    heap.insert(2);
    heap.insert(15);
    heap.insert(90);
    heap.insert(3);
    heap.insert(18);
    heap.insert(34);
    heap.heapify(0);

    cout << heap.extractmin();
}