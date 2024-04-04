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

Node *takeInput()
{
    int val;
    cout << "enter root" << endl;
    cin >> val;
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        int left;
        cout << "enter left" << endl;
        cin >> left;
        if (left != -1)
        {
            Node *leftchild = new Node(left);
            front->left = leftchild;
            q.push(leftchild);
        }

        int right;
        cout << "enter right" << endl;
        cin >> right;
        if (right != -1)
        {
            Node *rightchild = new Node(right);
            front->right = rightchild;
            q.push(rightchild);
        }
    }
    return root;
}

void Print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    Print(root->left);
    Print(root->right);
}

int main()
{
    Node *root = takeInput();
    Print(root);
}
