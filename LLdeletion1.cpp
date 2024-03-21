#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

Node *
convertToLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}
Node *deleteHead(Node *head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    Node *newHead = deleteHead(head);
    cout << newHead->data;
}