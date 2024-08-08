#include <numeric>

int f(vector<int> &A, int mid)
{
    int stud = 1;
    int pages = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] + pages <= mid)
        {
            pages = A[i] + pages;
        }
        else
        {
            pages = A[i];
            stud++;
        }
    }
    return stud;
}

int Solution::books(vector<int> &A, int B)
{
    if (B > A.size())
        return -1;
    int low = *max_element(A.begin(), A.end());
    int high = accumulate(A.begin(), A.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int val = f(A, mid);
        if (val <= B)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
