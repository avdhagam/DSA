#include<iostream>
using namespace std;

int findOdd(int arr[],int n)
{
    int res=arr[0];
    for(int i=1;i<n;i++)
    {
        res=res^arr[i];
    }
    return res;
}

int main()
{
    int arr[]= {1,2,2,3,3,1,1,4,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<findOdd(arr,size)<<endl;
    return 0;
}

