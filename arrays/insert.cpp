#include <iostream>
using namespace std;

/* arr[] = {1, 2, 3, _, _} n = 3 cap = 5 pos = 1, lets say we want to insert it at 1, idx = pos - 1 = 0 we move all elements from the index one position ahead,
    and then fill in the gap with the new array element. */

int insert(int arr[], int n, int x, int cap, int pos)

{
    if (n == cap)
    {
        return n;
    }
    int idx = pos - 1;
    for (int i = n - 1; i > idx; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[idx] = x;
    return (n + 1);
}

int main()
{
    int arr[] = {1, 2, 3, 0, 0};
    int newSize = insert(arr, 3, 4, 5, 1);

    // Print the modified array
    for (int i = 0; i < newSize; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
