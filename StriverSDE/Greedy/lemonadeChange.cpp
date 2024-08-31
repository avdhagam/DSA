class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fives = 0;
        int tens = 0;
        for (auto i : bills)
        {
            if (i == 5)
            {
                fives++;
            }
            else if (i == 10)
            {
                if (fives)
                {
                    tens++;
                    fives--;
                }
                else
                {
                    return false;
                }
            }
            else if (i == 20)
            {
                if (fives && tens)
                {
                    tens--;
                    fives--;
                }
                else if (fives >= 3)
                {
                    fives = fives - 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};