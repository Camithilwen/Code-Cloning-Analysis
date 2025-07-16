#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n,m;
  cin >> n >> m;
  vint A(n-1+m),B(n-1+m);
  vvint to(n);
  vint in(n);
  vint dist(n,0);
  rep(i,0,n-1+m){
    cin >> A[i] >> B[i];
    A[i]--;B[i]--;
    to[A[i]].push_back(B[i]);
    in[B[i]]++;
  }
  queue<int> que;
  vint ans(0,0);
  rep(i,0,n){
    if(in[i] == 0) que.push(i);
  }
  while(!que.empty()){
    int now = que.front();
    que.pop();
    ans.push_back(now);
    for(auto p : to[now]){
      in[p]--;
      if(in[p] == 0) que.push(p);
      dist[p] = max(dist[now]+1,dist[p]);
    }
  }
  vint par(n,-1);
  rep(i,0,n-1+m){
    int a = A[i];
    int b = B[i];
    if(dist[b] - dist[a] == 1) par[b] = a; 
  }
  rep(i,0,n) cout << par[i]+1 << endl;
}