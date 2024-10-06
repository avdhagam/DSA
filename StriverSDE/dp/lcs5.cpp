#include <vector>

int lcs(string s, string t)
{
    // Write your code here
    int i = s.size();
    int j = t.size();
    vector<int> prev(j + 1, 0);
    vector<int> cur(j + 1, 0);
    for (int ind1 = 1; ind1 <= i; ind1++)
    {
        for (int ind2 = 1; ind2 <= j; ind2++)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
            {
                cur[ind2] = 1 + prev[ind2 - 1];
            }
            else
            {

                cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
            }
        }
        prev = cur;
    }
    return cur[j];
}