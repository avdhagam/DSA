#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

class minheap
{
public:
    int size;
    vector<int> arr;
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
        if (lt < size && arr[lt] < arr[smallest])
        {
            smallest = lt;
        }
        if (rt < size && arr[rt] < arr[smallest])
        {
            smallest = rt;
        }
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    void decreasemin(int i, int x)
    {
        arr[i] = x;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void print()
    {
        for (auto i : arr)
        {
            cout << i << " ";
        }
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
    heap.decreasemin(2, 5);
    heap.print();
}