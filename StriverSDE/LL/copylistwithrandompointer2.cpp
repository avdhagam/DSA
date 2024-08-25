/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }

        temp = head;
        while (temp != NULL)
        {
            Node *copynode = temp->next;
            if (temp->random != NULL)
            {
                copynode->random = temp->random->next;
            }
            else
            {
                copynode->random = NULL;
            }
            temp = temp->next->next;
        }

        temp = head;
        Node *dnode = new Node(-1);
        Node *res = dnode;
        while (temp != NULL)
        {
            Node *copynode = temp->next;
            res->next = copynode;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dnode->next;
    }
};