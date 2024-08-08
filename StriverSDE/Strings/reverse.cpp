#include <stdio.h>
#include <iostream>
using namespace std;

void reverse(char name[])
{

    int s = 0;
    int e = strlen(name) - 1;
    while (s < e)
    {
        swap(name[s++], name[e--]);
    }
}

int main()
{
    char name[20];
    cout << "enter your name" << endl;
    cin >> name;
    reverse(name);
    cout << " reversed name is " << name << endl;
}