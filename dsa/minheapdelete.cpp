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
        for (int i = size - 1; i != 0 && arr[parent(i)] < arr[i];)
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void heapify(int i)
    {
        int lt = left(i);
        int rt = right(i);
        int smallest = i;
        if (lt < size && arr[smallest] > arr[lt])
        {
            smallest = lt;
        }
        if (rt < size && arr[smallest] > arr[rt])
        {
            smallest = rt;
        }
        if (i != smallest)
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
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        if (size > 0)
        {
            heapify(0);
        }
        return arr[size];
    }

    void decreasekey(int i, int x)
    {

        arr[i] = x;
        while (i != 0 && arr[i] < arr[parent(i)])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void deletekey(int i)
    {
        decreasekey(i, INT_MIN);
        extractmin();
    }

    void print()
    {
        for (auto i : arr)
        {
            if (i == INT_MIN)
            {
                continue;
            }
            cout << i << " ";
        }
        cout << endl;
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
    heap.print();
    cout << endl;
    heap.deletekey(2);
    heap.print();
}