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
        if (i != smallest)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
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
    heap.heapify(1);
    heap.print();
}