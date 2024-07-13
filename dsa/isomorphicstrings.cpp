#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    map<string, string> mp;
    for (auto i : s)
    {
        char original = s.at(i);
        char replacement = t.at(i);

        if (!mp.containsKey(original))
        {
            if (!mp.containsValue(replacement))
            {
                mp[original] = replacement;
            }
            else
            {
                return false;
            }
        }
        else
        {
            char fake = mp[original];
            if (fake != replacement)
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    bool ans = isIsomorphic("odd", "ass");
    cout << ans;
}