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
#include <deque>
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
#define pb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(vecll v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(vector<vec> v){for(auto e:v){for(auto ee:e)cout<<ee<<" ";cout<<endl;}}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}
const int INF=1e6;
const int MAX_ROW = 510; // to be set appropriately
const int MAX_COL = 510; // to be set appropriately
struct UnionFind{
    vector<int> par,sizes;
    UnionFind(int n):par(n+1),sizes(n+1,1){
        rep2(i,1,n)par[i]=i;
    }
    int find(int x){
        return (x==par[x]?x:par[x]=find(par[x]));
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return ;
        if(sizes[x]<sizes[y]){
            swap(x,y);
        }
        par[y]=x;
        sizes[x]+=sizes[y];
    }
    bool same(int x,int y) {return (find(x)==find(y));}
    int size(int x) {return sizes[find(x)];}
};
ll ans,d;
void solve(int n,vector<ll> v,vector<ll> w){
    vector<pair<ll,int>> x,y;
    rep(i,n){
        x.pb(v[i],i);
        y.pb(w[i],i);
    }
    sort(all(x));sort(all(y));
    vec b(n),c(n);
    vecll B(n),C(n);
    int now=0;
    rep(i,n){
        while(now<x[i].second){
            b[now]=x[i].second;
            B[now]=x[i].first+w[now];
            now++;
        }
    }
    B[n-1]=LONG_MAX;
    C[0]=LONG_MAX;
    now=n-1;
    rep(i,n){
        while(now>y[i].second){
            c[now]=y[i].second;
            C[now]=y[i].first+v[now];
            now--;
        }
    }
    UnionFind uf(n);
    // print(b);print(B);
    // print(c);print(C);
    rep(i,n){
        if(B[i]<C[i]){
            if(!uf.same(i,b[i])){
                ans+=B[i];
                uf.unite(i,b[i]);
            }
        }
        else{
            if(!uf.same(i,c[i])){
                ans+=C[i];
                uf.unite(i,c[i]);
            }
        }
    }
    map<int,vec> mp;
    rep(i,n){
        mp[uf.find(i)].pb(i);
    }
    if(mp.size()==1)return ;
    else{
        int nn=mp.size();
        vecll vvc,ww;
        for(auto vv:mp){
            ll t=LONG_MAX,s=LONG_MAX;
            for(auto e:vv.second){
                chmin(t,v[e]);
                chmin(s,w[e]);
            }
            vvc.push_back(t);
            ww.pb(s);
        }
        solve(nn,vvc,ww);
    }
}
main(){
    int n=in();d=in();
    vector<ll> v,w;
    vecll a;
    rep(i,n)a.pb(in());
    rep(i,n){
        v.pb(a[i]+d*i);
        w.pb(a[i]-d*i);
    }
    solve(n,v,w);
    cout<<ans;
}