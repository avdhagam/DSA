#include <stdio.h>
#include <iostream>
using namespace std;
#include <queue>
#include <vector>

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

vector<int> leaftoroot(Node *root)
{

    if (root == NULL)
    {
        return vector<int>();
    }
    if (root->left == NULL && root->right == NULL)
    {
        vector<int> output;
        output.push_back(root->data);
    }
    vector<int> rightans = leaftoroot(root->right);
    vector<int> leftans = leaftoroot(root->left);
    if (!leftans.empty())
    {
        rightans.push_back(root->data);
        return rightans;
    }
    if (!rightans.empty())
    {
        leftans.push_back(root->data);
        return leftans;
    }
    else
    {
        if (rightans.size() > leftans.size())
        {
            rightans.push_back(root->data);
            return rightans;
        }
        else
        {
            leftans.push_back(root->data);
            return leftans;
        }
    }
}

int main()
{
    Node *root = userInput();
    vector<int> ans = leaftoroot(root);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}