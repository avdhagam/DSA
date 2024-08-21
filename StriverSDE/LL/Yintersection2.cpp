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
Node *collisionpoint(Node *head1, Node *head2, int d)
{
    Node *t1 = head1;
    Node *t2 = head2;

    while (d != 0)
    {
        d--;
        t2 = t2->next;
    }
    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1;
}

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    Node *temp = firstHead;
    int N1 = 0;
    while (temp != NULL)
    {
        N1++;
        temp = temp->next;
    }
    temp = secondHead;
    int N2 = 0;
    while (temp != NULL)
    {
        N2++;
        temp = temp->next;
    }
    if (N2 > N1)
    {
        return collisionpoint(firstHead, secondHead, N2 - N1);
    }
    else
    {
        return collisionpoint(secondHead, firstHead, N1 - N2);
    }
}
