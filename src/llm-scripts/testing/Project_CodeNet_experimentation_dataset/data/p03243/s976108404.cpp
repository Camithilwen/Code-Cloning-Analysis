#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int temp=n;
    int lastdigit;
    int digits=0;
    while(n!=0){
        lastdigit=n%10;
        n/=10;
        digits++;
    }
    int result=0;
    while(digits){
        result*=10;
        digits--;
        result+=lastdigit;
    }
    if(result>=temp){
        cout<<result;
    }
    else
    {
        cout<<(result+111);
    }
}