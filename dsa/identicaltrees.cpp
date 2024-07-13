#include <stdio.h>
#include <iostream>
using namespace std;
#include <queue>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool identical(Node *Root1, Node *Root2)
{
    if (Root1 == NULL || Root2 == NULL)
    {
        return (Root1 == Root2);
    }
    return ((Root1->data == Root2->data) && identical(Root1->left, Root2->left) && identical(Root1->right, Root2->right));
}

Node *userInput()
{
    int val;
    cout << "enter root val " << endl;
    cin >> val;
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        int right;
        cout << "enter right value" << endl;
        cin >> right;
        if (right != -1)
        {
            Node *rightnode = new Node(right);
            front->right = rightnode;
            q.push(rightnode);
        }

        int left;
        cout << "enter left value" << endl;
        cin >> left;
        if (left != -1)
        {
            Node *leftnode = new Node(left);
            front->left = leftnode;
            q.push(leftnode);
        }
    }
    return root;
}

int main()
{
    Node *Root1 = userInput();
    Node *Root2 = userInput();
    cout << identical(Root1, Root2);
}