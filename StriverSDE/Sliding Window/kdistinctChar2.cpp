#include <map>

int kDistinctChars(int k, string &str)
{
    // Write your code here
    int l = 0;
    int r = 0;
    int maxlen = 0;
    map<int, int> mp;
    while (r < str.size())
    {
        mp[str[r]]++;
        if (mp.size() > k)
        {
            mp[str[l]]--;
            if (mp[str[l]] == 0)
                mp.erase(str[l]);
            l++;
        }
        if (mp.size() <= k)
            maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}
