

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
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *Newnode = new Node(arr[i]);
        temp->next = Newnode;
        temp = temp->next;
    }
    return head;
}

void printNthFromEnd(Node *head, int n)
{
    if (head == NULL)
        return;
    Node *first = head;

    for (int i = 0; i < n; i++)
    {
        first = first->next;
    }
    Node *second = head;
    Node *temp = head;
    while (first != NULL)
    {
        temp = second;
        first = first->next;
        second = second->next;
    }
    cout << second->data;
    temp->next = second->next;
    delete (second);
}
void print(Node *head)
{
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        cout << curr->data << " ";
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = ArrayToLL(arr);
    printNthFromEnd(head, 3);
    print(head);
}