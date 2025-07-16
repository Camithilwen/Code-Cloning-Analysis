#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    int temp=x;
    int sum=0;
    while(temp!=0)
    {
        sum+=temp%10;
        temp/=10;
    }
    if(x%sum==0)
    {
        cout<<"Yes";
    }
    else
    cout<<"No";
}