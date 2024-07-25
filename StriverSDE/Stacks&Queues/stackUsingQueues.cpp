class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            int node = q1.front();
            q1.pop();
            q2.push(node);
        }
        swap(q1, q2);
    }

    int pop()
    {
        int res = q1.front();
        q1.pop();
        return res;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};