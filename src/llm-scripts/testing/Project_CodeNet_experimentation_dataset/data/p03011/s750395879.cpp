#include<iostream>
using namespace std;
int main(){
    int a,b,c,sum,maxim;
    cin>>a>>b>>c;
    sum=a+b+c;
    maxim=max(a,b);
    maxim=max(maxim,c);
    cout<<sum-maxim;
}
