class Solution
{
public:
    bool check(int a[26], int b[26])
    {

        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        int count1[26] = {0};
        int window = s1.length();
        for (int i = 0; i < window; i++)
        {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        int i = 0;
        int count2[26] = {0};
        while (i < window && i < s2.length())
        {
            int newchar = s2[i] - 'a';
            count2[newchar]++;
            i++;
        }

        if (check(count1, count2))
        {
            return true;
        }

        while (i < s2.length())
        {
            int newchar = s2[i] - 'a';
            count2[newchar]++;

            int oldchar = s2[i - s1.length()] - 'a';
            count2[oldchar]--;

            if (check(count2, count1))
            {
                return 1;
            }

            i++;
        }

        return 0;
    }
};