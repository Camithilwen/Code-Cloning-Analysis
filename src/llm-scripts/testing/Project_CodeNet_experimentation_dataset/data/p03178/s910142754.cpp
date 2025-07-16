// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "S - Digit Sum"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int mod = 1e9 + 7;

void addmod(ll &x, ll val){
    x+=val;
    if (x>mod) x-=mod;
    if (x<0) x+=mod;
}
int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");

    string  x;
    int d;
    cin>>x;
    cin>>d;
    ll cur = 0;
    vector<ll> tmp(d,0);
    vector<ll> dp(d,0);
    for(int i=0;i<x.len;i++){

        for(int j = 0;j<d;j++)
            for(int k=0;k<=9;k++) addmod(tmp[ (j+k)%d  ], dp[j]);

        for(int j = 0;j<x[i]-'0';j++) addmod( tmp[(cur + j)%d],1LL);
        dp = tmp;
        fill(tmp.begin(),tmp.end(),0);
        //addmod(cur,0LL+x[i]-'0');
        cur = (cur + x[i]-'0')%d;
    }
    //show(dp[0]);
    //show(cur);
    cout<<dp[0] + (cur==0) - 1<<endl;

}
