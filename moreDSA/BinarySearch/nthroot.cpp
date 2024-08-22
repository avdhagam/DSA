int mult(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 1;
    }

    if (ans == m)
        return 2;
    else
        return 3;
}

int NthRoot(int n, int m)
{
    // Write your code here.
    int low = 1;
    int high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mult(mid, n, m) == 2)
            return mid;
        else if (mult(mid, n, m) == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}