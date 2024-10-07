int f(int i, int j, string str1, string str2)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (str1[i] == str2[j])
    {
        return 0 + f(i - 1, j - 1, str1, str2);
    }
    else
    {
        int insert = 1 + f(i, j - 1, str1, str2);
        int deletee = 1 + f(i - 1, j, str1, str2);
        int replace = 1 + f(i - 1, j - 1, str1, str2);
        return min(insert, min(deletee, replace));
    }
}

int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.size();
    int m = str2.size();

    return f(n - 1, m - 1, str1, str2);
}