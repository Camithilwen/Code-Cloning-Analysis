#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <cstdio>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
# define ll int64_t
# define str string
# define rep(i,n) for(ll i=0;i<n;i++)
# define rrep(i,n) for(ll i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define mod 1000000007
# define PI 3.141592653589793
# define vec vector
#define dump(x) cerr<<#x<<"="<<x<<endl
using namespace std;



#define INF 2000000000
#define MAX_V 10
const int MAX_N =10000000;


bool compare_by_b(pair<string,ll> a,pair<string,ll> b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

bool my_compare(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first != b.first) return a.first<b.first;
    if(a.second != b.second) return a.second>b.second;
    else return true;
}

ll modpow(ll a,ll n,ll mod1) {
    ll res=1;
    while(n>0){
        if(n&1) res=res*a%mod1;
        a = a*a%mod1;
        n >>= 1;
    }
    return res;
}

ll factorial(ll n){
    ll x=1;
    rrep(i,n) x*=i;
    return x;
}

ll gcd(ll a,ll b) { return b ? gcd(b, a%b) : a; }

ll func(ll a,ll b,ll& ans_x,ll& ans_y){
    if(b == 0){
        ans_x = 1;
        ans_y = 0;
        return a;
    }else{
        ll ret = func(b,(a%b),ans_y,ans_x);
        ans_y -= (a/b)*ans_x;
        return ret;
    }
}

ll par[MAX_N],ranking[MAX_N];

void init(ll n){
    rep(i,n){
        par[i]=i;
        ranking[i]=0;
    }
}

ll find(ll x){
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}

void unite(ll x,ll y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    
    if(ranking[x]<ranking[y]) par[x]=y;
    else{
        par[y]=x;
        if(ranking[x]==ranking[y]) ranking[x]++;
    }
}

bool same(ll x,ll y){
    return find(x)==find(y);
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,m;
    cin>>n>>m;
    map<ll,ll> mp;
    for(ll i=1;i*i<=m;i++){
        if(m%i==0){
            if(i==m/i) mp[i]+=m/i;
            else {
                mp[m/i]+=i;
                mp[i]+=m/i;
            }
        }
    }
    ll maxi=1;
    for(auto p:mp){
        if(p.second>=n || p.first<=m/n) maxi=max(p.first,maxi);
    }
    cout<<maxi<<endl;
    return 0;
}
