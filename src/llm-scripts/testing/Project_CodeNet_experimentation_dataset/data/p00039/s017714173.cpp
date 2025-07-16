#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string a;
    int num[101],cou=0,ans;
    while(cin>>a){
        for(int i=0;i<a.size();i++){
        if(a[i]=='I')num[i]=1;
        if(a[i]=='V')num[i]=5;
        if(a[i]=='X')num[i]=10;
        if(a[i]=='L')num[i]=50;
        if(a[i]=='C')num[i]=100;
        if(a[i]=='D')num[i]=500;
        if(a[i]=='M')num[i]=1000;
    }
    ans=num[a.size()-1];
    for(int i=a.size()-1;i>0;i--){
        if(num[i]>num[i-1])ans=ans-num[i-1];
        if(num[i]<=num[i-1])ans=ans+num[i-1];
    }
    cout<<ans<<endl;
}
return 0;
}