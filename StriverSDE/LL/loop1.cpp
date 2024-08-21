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
bool detectCycle(Node *head)
{
    //	Write your code here
    map<Node *, int> mp;
    Node *temp = head;
    while (temp != NULL)
    {
        if (mp.find(temp) != mp.end())
        {
            return true;
        }
        mp[temp] = 1;
        temp = temp->next;
    }
    return false;
}