#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here.
    Node<int> *t1 = first;
    Node<int> *t2 = second;
    Node<int> *dnode = new Node<int>(-1);
    Node<int> *temp = dnode;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data > t2->data)
        {
            temp->next = t2;
            temp = temp->next;
            t2 = t2->next;
        }
        else
        {
            temp->next = t1;
            temp = temp->next;
            t1 = t1->next;
        }
    }
    if (t1)
    {
        temp->next = t1;
    }
    else
    {
        temp->next = t2;
    }
    return dnode->next;
}
