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

Node *ArrayToLL(vector<int> arr)
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

void *removeNthNode(Node *head, int n)
{
    int size = 0;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        size++;
    }
    if (size < n)
    {
        cout << "oops";
        }
    Node *curr = head;
    Node *temp = head;
    for (int i = 1; i < size - n + 1; i++)
    {
        temp = curr;
        curr = curr->next;
    }
    temp->next = curr->next->next;
    delete (curr);
}

void print(Node *head)
{
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        cout << curr->data << endl;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *head = ArrayToLL(arr);
    removeNthNode(head, 1);
    print(head);
}