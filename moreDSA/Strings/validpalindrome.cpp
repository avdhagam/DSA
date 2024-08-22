class Solution
{
public:
    bool isvalid(char s)
    {
        if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9'))
        {
            return true;
        }
        return false;
    }
    char lower(char s)
    {
        if (s <= 'z' && s >= 'a')
        {
            return s;
        }
        else
        {
            char temp;
            temp = s - 'A' + 'a';
            return temp;
        }
    }

    bool checkpalin(string temp)
    {
        int s = 0;
        int e = temp.length() - 1;
        while (s <= e)
        {
            if (temp[s] != temp[e])
            {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }

    bool isPalindrome(string s)
    {
        string temp = "";
        for (int j = 0; j < s.length(); j++)
        {
            if (isvalid(s[j]))
            {
                temp += s[j];
            }
        }
        for (int j = 0; j < temp.size(); j++)
        {
            temp[j] = lower(temp[j]);
        }

        return checkpalin(temp);
    }
};