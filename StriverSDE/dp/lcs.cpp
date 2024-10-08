int f(int ind1, int ind2, string s, string t)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (s[ind1] == t[ind2])
    {
        return 1 + f(ind1 - 1, ind2 - 1, s, t);
    }

    return max(f(ind1 - 1, ind2, s, t), f(ind1, ind2 - 1, s, t));
}

int lcs(string s, string t)
{
    // Write your code here
    int i = s.size();
    int j = t.size();
    return f(i - 1, j - 1, s, t);
}