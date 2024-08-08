#include <stdio.h>
#include <iostream>
using namespace std;

bool palindrome(char name[])
{
    int s = 0;
    int e = strlen(name) - 1;
    while (s < e)
    {
        if (name[s++] != name[e--])
            return false;
    }
    return true;
}

int main()
{
    char name[20];
    cout << "enter ur name" << endl;
    cin >> name;
    palindrome(name) ? cout << "palindrome" : cout << "not a palindrome";
}