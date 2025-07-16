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
void makegraph(int x,vector<vec> &v){rep(i,x-1){int a=in(),b=in();v[a].pb(b);v[b].pb(a);}}
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}
#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=1e9+7;
#define N 255050

ll n,m,k;
ll a[N],x[N];
int mv[80][N];

main(){
    n=in();
    rep(i,n)x[i]=in();
    m=in();
    k=lin();
    rep(i,m)a[i]=in();
    rep(i,n-1)mv[0][i]=i;
    rep(i,m)swap(mv[0][a[i]-1],mv[0][a[i]-2]);
    rep(i,63){
        rep(j,n-1){
            mv[i+1][j]=mv[i][mv[i][j]];
        }
    }
    /*
    rep(i,3){
        rep(j,n)cout<<mv[i][j]<<" ";
        cout<<endl;
    }
    */
    vec now(n),temp(n);
    rep(i,n-1)now[i]=i;
    rep(i,63){
        if(k&(1ll<<i)){
            rep(j,n-1){
                temp[j]=now[mv[i][j]];
                /*printf("mv[i][j]=%d now[mv[i][j]]=%d\n",mv[i][j],now[mv[i][j]]);
                */
            }
            /*cout<<"now="<<i<<endl;
            rep(ii,n-1)cout<<temp[i]<<" ";
            cout<<endl;
            */
            now=temp;        
        }
    }
    /*
    rep(i,n-1)cout<<now[i]<<" ";
    cout<<endl;
    */
    vec d(n);
    rep(i,n-1)d[i]=x[i+1]-x[i];
    /*
    rep(i,n-1)cout<<d[i]<<" ";
    */
    cout<<x[0]<<endl;
    rep(i,n-1){
        x[i+1]=x[i]+d[now[i]];
        cout<<x[i+1]<<endl;
    }
}