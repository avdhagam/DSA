#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *y = new Node(arr[1]);
    cout << y->data;
}