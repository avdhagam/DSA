#include<iostream>
using namespace std;

//naive method

int findOdd( int arr[] , int n)
{
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if(count%2!=0)
        {
            return arr[i];
        }
    }
}

int main()
{
    int arr[] = {1,1,2,5,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<findOdd(arr,size);
    return 0;
}