#include <iostream>
using namespace std;

void iskthset(int n,int k)
{
    int x=(1<<(k-1));
    if((n&x)!=0){
        cout<<"kth bit is set"<<endl;
    }
    else{
        cout<<"kth bit is not set"<<endl;
    }
} 
int main(){
    iskthset(5,2);
    return 0;
}
