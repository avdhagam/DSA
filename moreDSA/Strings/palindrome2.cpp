#include <stdio.h>
#include <iostream>
using namespace std;

char lowercase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool ispalindrome(char word[])
{
    int s = 0;
    int e = strlen(word) - 1;
    while (s <= e)
    {
        if (lowercase(word[s]) != lowercase(word[e]))
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
    }
    return 1;
}

int main()
{
    char word[20];
    cout << "enter word" << endl;
    cin >> word;
    ispalindrome(word) ? cout << "palindrome" : cout << "not a palindrome";
}