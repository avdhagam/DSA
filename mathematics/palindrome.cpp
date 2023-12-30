#include<iostream>
using namespace std;

bool isPalindrome(int x){
    int temp=x;
    int reverse=0;
    while(temp!=0){
         reverse=reverse*10+(temp%10);
         temp=temp/10;
    }
    return(reverse == x);
}

int main(){
    int num;
    cout<<"enter a number to be checked"<<endl;
    cin>>num;
    if(isPalindrome(num)==0){
        cout<<"not a palindrome"<<endl;
    }
    else{
        cout<<"palindrome"<<endl;
    }

}