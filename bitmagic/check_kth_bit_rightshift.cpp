#include<iostream>
using namespace std;

void iskthbitset(int n,int k)
{
    int x=n>>(k-1);
    if((x&1)!=0){
        cout<<("kth bit is set")<<endl;
    }
    else{
        cout<<"kth bit is not set"<<endl;
    }
}

int main(){
    iskthbitset(4,3);
    return 0;
}