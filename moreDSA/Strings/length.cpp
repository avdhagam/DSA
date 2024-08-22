#include <stdio.h>
#include <iostream>
using namespace std;

int getlength(char name[])
{
    int cnt = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        cnt++;
    }
    return cnt;
}

int main()
{
    char name[20];
    cout << "enter name" << endl;
    cin >> name;
    int len = getlength(name);
    cout << "length of name:" << len;
}