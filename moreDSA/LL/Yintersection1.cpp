/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
#include <map>
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    Node *temp = firstHead;
    map<Node *, int> mp;
    while (temp != NULL)
    {
        mp[temp] = 1;
        temp = temp->next;
    }
    temp = secondHead;
    while (temp != NULL)
    {
        if (mp.find(temp) != mp.end())
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
