#include <stdio.h>
#include <iostream>
using namespace std;
#include <stack>

int bracketReversal(string input)
{
    int size = input.length();
    stack<char> tempstack;
    if (size == 0)
    {
        return 0;
    }
    if (size % 2)
    {
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        if (input[i] == '{')
        {
            tempstack.push(input[i]);
        }
        else
        {
            if (!tempstack.empty() && tempstack.top() == '{')
            {
                tempstack.pop();
            }
            else
            {
                tempstack.push(input[i]);
            }
        }
    }

    int answer = 0;
    while (!tempstack.empty())
    {
        char c1 = tempstack.top();
        tempstack.pop();
        char c2 = tempstack.top();
        tempstack.pop();
        if (c1 == c2)
        {
            answer += 1;
        }
        else
        {
            answer += 2;
        }
    }
    return answer;
}

int main()
{
    cout << bracketReversal("{}{{{{");
}