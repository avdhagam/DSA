#include<iostream>
using namespace std;



int countsetbits(int n){
    int res = 0;
    while(n>0)
    {
        res=res+(n&1); 
        //adds 1 only if last bit is set
        n=n/2;
    }

    return res;
}

int main()
{
    cout<<"hey"<<endl;
    cout<<countsetbits(5)<<endl;
    return 0;
}