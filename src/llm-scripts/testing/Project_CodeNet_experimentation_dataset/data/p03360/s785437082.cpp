#include<iostream>
using namespace std;
int main(){
    unsigned long long int a,b,c,k;
    cin>>a>>b>>c>>k;
    unsigned long long int sum=a+b+c;
    unsigned long long int term=max(a,max(b,c));
    sum-=term;
    while(k)
    {
        term*=2;
        k--;
    }
    cout<<sum+term;
}