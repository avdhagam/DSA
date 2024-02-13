#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

int secondLargest(int arr[], int n)
{
    int largest = arr[0];
    int slargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > slargest)
        {
            slargest = arr[i];
        }
    }
    return slargest;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 4, 3};
    int index = secondLargest(arr, sizeof(arr) / sizeof(arr[0]));
    if (index == -1)
    {
        cout << " The second largest doesnt exist" << endl;
    }
    else
    {
        cout << "The second largest is" << arr[index];
    }
}
