#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    int a,b;
    cin>>a>>b>>s;
    bool flag=true;
    for(int i=0;i<a;i++){
        int num=s[i]-'0';
        if(num<0||num>9)flag=false;
    }
    if(s[a]!='-')flag=false;
    for(int i=a+1;i<a+b+1;i++){
        int num=s[i]-'0';
        if(num<0||num>9)flag=false;
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}