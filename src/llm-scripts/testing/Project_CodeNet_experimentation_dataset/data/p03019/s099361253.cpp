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
#define N 500000
ll MOD=1e9+7;
vec mem(20,-1);
main(){
    int n=in();
    ll x=in();
    vector<ll> b,l,r,t;
    rep(i,n){
        b.pb(in());
        l.pb(in());
        r.pb(in());
        t.pb(l[i]*b[i]+(r[i])*(x-b[i]));
    }
    vec ind;
    rep(i,n)ind.pb(i);
    sort(all(ind),[&](int y,int z){
        return t[y]>t[z];
    });
    //cout<<t[0]<<" "<<t[1]<<endl;
    ll left=-1,right=n*x;
    while(left<right-1){
        ll mid=(left+right)/2;
        ll mm=mid;
        ll tmp=0;
        rep(i,n){
            tmp-=b[i]*l[i];
        }
        int now=0;
        bool flag=false;
        while(mid>=x){
            tmp+=t[ind[now]];
            if(tmp>=0){
                flag=true;break;
            }
            mid-=x;
            now++;
        }
        if(flag){
            right=mm;continue;
        }
        ll MAX=0;
        ll T=1e11;
        rep2(j,0,now-1){
            int i=ind[j];
            if(mid>=b[i]){
                T=min(T,(x-mid)*r[i]);
            }
            else{
                T=min(T,(x-b[i])*r[i]+(b[i]-mid)*l[i]);
            }
        }
        rep2(j,now,n-1){
            int i=ind[j];
            if(mid>=b[i]){
                MAX=max(MAX,b[i]*l[i]+(mid-b[i])*r[i]);
            }
            else{
                MAX=max(MAX,l[i]*mid);
            }
            MAX=max(MAX,t[i]-T);
        }
        tmp+=MAX;
        if(tmp>=0)right=mm;
        else left=mm;
    }
    cout<<right;
}

