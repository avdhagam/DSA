#include<iostream>
using namespace std;

bool poweroftwo(int n)
{
    return (n&&(n&(n-1))==0);
}

int main(){
    cout<<poweroftwo(4)<<endl;
    return 0;
}
