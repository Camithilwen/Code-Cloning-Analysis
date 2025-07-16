#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt,ts,h,t,o,a,b,tmp,count=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        tmp=i;
        tt=tmp/10000;
        tmp-=tt*10000;
        ts=tmp/1000;
        tmp-=ts*1000;
        h=tmp/100;
        tmp-=h*100;
        t=tmp/10;
        tmp-=t*10;
        o=tmp;
        if((tt==o)&&(ts==t))count++;
    }
    cout<<count<<endl;
    return 0;
}