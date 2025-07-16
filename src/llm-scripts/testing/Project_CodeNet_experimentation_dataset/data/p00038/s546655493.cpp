#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

#define loop(i,a,b) for(int i=a; i<b; i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
    int a[5];
    while(scanf("%d,%d,%d,%d,%d",&a[0],&a[1],&a[2],&a[3],&a[4])!=EOF){
        sort(a,a+5);
        int n=0;
        rep(i,4)loop(j,i+1,5){
            if(a[i]==a[j])n++;
        }
        bool st=true;
        rep(i,4)if(a[i]+1!=a[i+1])st=false;
        if(a[0]==1&&
           a[1]==10&&
           a[2]==11&&
           a[3]==12&&
           a[4]==13) st=true;

        string ans;
        if(n==6)
            ans="four card";
        else if(n==4)
            ans="full house";
        else if(st)
            ans="straight";
        else if(n==3)
            ans="three card";
        else if(n==2)
            ans="two pair";
        else if(n==1)
            ans="one pair";
        else
            ans="null";
        cout<<ans<<endl;
    }
}