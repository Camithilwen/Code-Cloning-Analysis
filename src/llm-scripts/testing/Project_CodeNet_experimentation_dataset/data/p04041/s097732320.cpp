#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=1e9+7;
#define N 1055050
ll dp[50][1<<20];
vector<ll> change(int x){
    vector <ll> v;
    int count=0;
    while(x){
        count++;
        if(x%2){v.pb(count);count=0;}
        x/=2;
    }
    return v;
}
int change2(vector<ll> v){
    ll now=1;
    ll ans=0;
    for(auto e:v){
        rep(i,e)now*=2;
        ans+=now/2;
    }
    return ans;
}
bool judge[N];
ll pw[50];
main(){
    ll n=in();
    ll x[3];
    rep(i,3)x[i]=in();
    int sum=x[0]+x[1]+x[2];
    swap(x[0],x[2]);
    vector<pair<vector<ll>,ll>> v;
    vector<ll> vvv;
    v.pb({vvv,1ll});
    ll ans=0;
    pw[0]=1;
    rep(i,20)pw[i+1]=pw[i]*2;
    dp[0][0]=1;
    vector<ll> tmp={2,3};
    rep(i,1<<sum){
        vector<ll> s=change(i);
        int state=0;
        int now[3]={};
        rep(kk,s.size()){
            if(state==3)break;
            if(now[state]+s[kk]<x[state])now[state]+=s[kk];
            else if(now[state]+s[kk]==x[state])state++;
            else {state=-1;break;}
        }
        judge[i]=(state==3?1:0);
    }
    rep(i,n){
        rep(k,1<<sum){
            if(dp[i][k]==0)continue;
            rep2(j,1,7){
                vector<ll> s(1,j);
                ll next=(k*pw[j]+pw[j-1])%pw[sum];
                if(!judge[next])
                dp[i+1][next]=(dp[i][k]+dp[i+1][next])%MOD;
            }
            dp[i+1][0]=(dp[i+1][0]+dp[i][k]*3)%MOD;
        }
    }
    ll p=1;
    rep(i,n){
        p=p*10ll%MOD;
    }
    rep(i,1<<sum){
        p=(p-dp[n][i]+MOD)%MOD;
    }
    cout<<p<<endl;
}
