class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int cnt = 0;
        vector<int> lastSeen(3, -1);
        for (int i = 0; i < s.size(); i++)
        {
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
            {
                cnt += (1 + *min_element(lastSeen.begin(), lastSeen.end()));
            }
        }
        return cnt;
    }
};