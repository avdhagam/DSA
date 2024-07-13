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
arraytoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}

Node *insertAtValue(Node *head, int x)
{
    Node *temp = head;
    while (temp->next != NULL && temp->next->data < x)
    {
        temp = temp->next;
    }
    Node *curr = new Node(x);
    curr->next = temp->next;
    temp->next = curr;
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    vector<int> arr = {1, 10, 20, 30};
    Node *head = arraytoLL(arr);
    Node *temphead = insertAtValue(head, 25);
    print(temphead);
}