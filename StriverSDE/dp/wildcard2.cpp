bool f(int i, int j, string pattern, string text)
{
    if (i == 0 && j == 0)
        return true;
    if (i == 0 && j > 0)
        return false;
    if (i > 0 && j == 0)
    {
        for (int ii = 0; ii <= i; ii++)
        {
            if (pattern[ii] != '*')
                return false;
        }
        return true;
    }

    if (pattern[i] == text[j] || pattern[i] == '?')
        return f(i - 1, j - 1, pattern, text);
    if (pattern[i] == '*')
    {
        return f(i - 1, j, pattern, text) || f(i, j - 1, pattern, text);
    }
    return false;
}

bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    int n = pattern.size();
    int m = text.size();
    return f(n, m, pattern, text);
}
