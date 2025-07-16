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
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 3000000
ll MOD=998244353;

ll inv[N],prd[N],invprd[N];
void calc_inv(){
    inv[1]=1;
    rep2(i,2,N-1){
        inv[i]=((-(MOD/i)*inv[MOD%i])%MOD+MOD)%MOD;
    }
    return;
}
void calc_product(){
    prd[0]=prd[1]=1;
    invprd[0]=invprd[1]=1;
    rep2(i,2,N-1){
        prd[i]=i*prd[i-1]%MOD;
        invprd[i]=inv[i]*invprd[i-1]%MOD;
    }
    return ;
}
ll cmb(ll a,ll b){
    if(a<b)return 0;
    if(a<0||b<0)return 0;
    return prd[a]*invprd[b]%MOD*invprd[a-b]%MOD;
}
ll modpow(ll x,ll n){
    if(n==0) return 1;
    ll res=modpow(x*x%MOD,n/2);
    if(n&1) res=res*x%MOD;
    return res;
}

main(){
    calc_inv();
    calc_product();
    ll n=lin(),m=lin();
    ll ans=0;
    ans=cmb(m*3ll+n-1ll,n-1ll);
    rep2(x,1,m){
        ans=(ans+MOD-n*cmb(m+n-x-2ll,n-2ll)%MOD)%MOD;
        if(cmb(m+n-x-2ll,n-2ll)<0)cout<<0000;
        if(n*cmb(m+n-x-2ll,n-2ll)<0)cout<<000;
        //cout<<ans<<endl;
    }
    ll t=-1;
    ll p=m,q=m;
    rep2(x,m+1,(ll)min(m*3,n)){
        
        if(x>n)break;
        //ans=(ans+MOD-t*cmb(n,x)*cmb(p-q-1,q-1)%MOD)%MOD;
        if(n==x){
            if(m*3==n)
            ans=(ans+MOD+t*cmb(p,q)%MOD)%MOD;
            //cout<<ans<<endl;
        }
        if((m*3-x)%2)continue;
        ans=(ans+MOD+t*cmb(n,x)%MOD*cmb((m*3-x)/2+n-1,n-1)%MOD)%MOD;
    }
    cout<<ans<<endl;
}

