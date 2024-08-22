#include <vector>

char highestOccurringChar(char input[])
{
    // Write your code here
    int len = strlen(input);
    vector<int> ans(26, 0);
    for (int i = 0; i < len; i++)
    {
        int num = -1;
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            num = input[i] - 'a';
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            num = input[i] - 'A';
        }
        ans[num]++;
    }

    int maxi = -1;
    int a = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (maxi < ans[i])
        {
            a = i;
            maxi = ans[i];
        }
    }
    return 'a' + a;
}