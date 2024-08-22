void reverse(int s, int e, string &str)
{

    while (s < e)
    {
        swap(str[s++], str[e--]);
    }
}

string reverseOrderWords(string str)
{
    // Write your code here
    int x = 0;
    reverse(0, str.length() - 1, str);
    for (int i = 0; i < str.length() + 1; i++)
    {
        if (str[i] == ' ')
        {
            reverse(x, i - 1, str);
            x = i + 1;
        }
        if (i == str.length())
        {
            reverse(x, i - 1, str);
        }
    }
    return str;
}