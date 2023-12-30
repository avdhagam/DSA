#include<iostream>
using namespace std;

int countdigits(int x){
    int num,count=0;
    while(x!=0){
        x=x/10;
        count++;
    }
    return count;
}

int main()
{
    cout<<countdigits(-34555);
}