#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,num[3]={0};
    cin>>n;
    cin>>num[0]>>num[1];
    if(n==3)cin>>num[2];
    sort(num,num+2);
    for(int i=1;i<=num[0];i++){
        if(num[0]%i==0&&num[1]%i==0&&num[2]==0)cout<<i<<endl;
        else if(num[0]%i==0&&num[1]%i==0&&num[2]%i==0)cout<<i<<endl;
    }
    return 0;
}