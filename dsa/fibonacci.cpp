#include <iostream>
#include <vector>

using namespace std;

int helper1(int n, vector<int> &ans);

// recursion
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a = fib(n - 1);
    int b = fib(n - 2);
    return a + b;
}

// memoization
int fib1(int n)
{
    vector<int> ans(n + 1, -1); // Initializing the memoization array with -1
    return helper1(n, ans);
}

int helper1(int n, vector<int> &ans)
{
    if (n <= 1)
    {
        return n;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int a = helper1(n - 1, ans);
    int b = helper1(n - 2, ans);
    ans[n] = a + b;
    return ans[n];
}

int main()
{
    cout << fib(3) << endl;
    cout << fib1(3) << endl;
    return 0;
}
