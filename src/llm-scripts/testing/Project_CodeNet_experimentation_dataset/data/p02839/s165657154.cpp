#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <algorithm> 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<"\n"
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
template<class T> inline bool chmax(T& a, T b) { 
 if (a < b) { a = b; return true; } return false; 
}
template<class T> inline bool chmin(T& a, T b) {
 if (a > b) { a = b; return true; } return false; 
}
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll h,w;
  cin>>h>>w;
  vvll a(h,vll(w));
  vvll b(h,vll(w));
  rep(i,h)rep(j,w) cin>>a[i][j];
  rep(i,h)rep(j,w) cin>>b[i][j];
  vector<vvb> dp(h,vvb(w,vb(160*80,false)));
  dp[0][0][abs(a[0][0]-b[0][0])]=true;
  rep(i,h)rep(j,w)rep(z,160*80){
    if(dp[i][j][z]){
      if(i+1<h){
      dp[i+1][j][z+abs(a[i+1][j]-b[i+1][j])]=true;
      dp[i+1][j][abs(z-abs(a[i+1][j]-b[i+1][j]))]=true;
      }
      if(j+1<w){
      dp[i][j+1][z+abs(a[i][j+1]-b[i][j+1])]=true;
      dp[i][j+1][abs(z-abs(a[i][j+1]-b[i][j+1]))]=true;
      }
    }
  }
  rep(i,160*80){
    if(dp[h-1][w-1][i]){
      COUT(i);
      return 0;
    }
  }
}