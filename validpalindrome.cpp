#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

bool isPalindrome(vector<char> &str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    return (str[start] == str[end]) && isPalindrome(str, start + 1, end - 1);
}

int main()
{
    const char charArray[] = "aabb";
    vector<char> str(charArray, charArray + sizeof(charArray) - 1);
    cout << isPalindrome(str, 0, str.size() - 1);

    return 0;
}