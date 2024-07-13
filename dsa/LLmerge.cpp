#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

Node *mergeLL(Node *h1, Node *h2)
{
    Node *fh = NULL;
    Node *ft = NULL;
    if (h1->data <= h2->data)
    {
        fh = h1;
        ft = h1;
        h1 = h1->next;
    }
    else
    {
        fh = h2;
        ft = h2;
        h2 = h2->next;
    }
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data <= h2->data)
        {
            fh = h1;
            ft = h1;
            h1 = h1->next;
        }
        else
        {
            fh = h2;
            ft = h2;
            h2 = h2->next;
        }
    }
    if (h1 != NULL)
    {
        ft->next = h2;
    }
    else
    {
        ft->next = h1;
    }
    return fh;
}

Node *createNode()
{
    int data;
    cin >>
        data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head != NULL)
        {
            tail->next = newnode;
            tail = tail->next;
        }
        else
        {
            head = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

int main()
{
    int data;
    Node *head1 = createNode();
    printLL(head1);
    Node *head2 = createNode();
    printLL(head2);
    Node *ans = mergeLL(head1, head2);
    printLL(ans);
}