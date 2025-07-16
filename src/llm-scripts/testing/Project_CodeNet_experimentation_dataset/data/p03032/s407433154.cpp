#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
using V = vector<ll>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll hcnt[300005],wcnt[300005];

int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> v(N);
  rep(i,N) cin>>v[i];
  ll ans = -INF;
  rep(i,N+1){
    rep(j,N-i+1){
      if(i+j>K)continue;
      priority_queue<ll,vector<ll>,greater<ll>> q;
      rep(k,i) q.push(v[k]);
      rep(k,j) q.push(v[N-k-1]);
      rep(k,K-i-j){
        if(q.empty()) break;
        if(q.top()<0) q.pop();
      }
      ll cnt = 0;
      while(!q.empty()) {
        cnt += q.top();
        q.pop();
      }
      chmax(ans,cnt);
    }
  }
  cout<<ans<<endl;
}