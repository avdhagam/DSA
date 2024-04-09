#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
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

Node *UserInput()
{
    cout << "enter root val";
    int val;
    cin >> val;
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        int right;
        cout << "enter right" << endl;
        cin >> right;
        if (right != -1)
        {
            Node *rightnode = new Node(right);
            front->right = rightnode;
            q.push(rightnode);
        }

        int left;
        cout << "enter left" << endl;
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

pair<int, int> diameter(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = diameter(root->left);
    pair<int, int> rightAns = diameter(root->right);

    int rh = rightAns.first;
    int rd = rightAns.second;

    int lh = leftAns.first;
    int ld = leftAns.second;

    int heightTree = 1 + max(rh, lh);
    int diameterTree = max(max(rd, ld), rh + lh);

    pair<int, int> ans;
    ans.first = heightTree;
    ans.second = diameterTree;

    return ans;
}

int main()
{
    Node *root = UserInput();
    pair<int, int> ans = diameter(root);
    cout << ans.first << endl;
    cout << ans.second << endl;
}
