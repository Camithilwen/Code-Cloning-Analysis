#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct BIT{
  int N;
  int bit[1000010];
  void add(int a,int w){
    for(int x = a; x < N; x+=(x&-x)) bit[x]+=w;
  }
  int sum(int a){
    int ret = 0;
    for ( int x = a; x > 0;x-=(x&-x)) ret += bit[x];
    return ret;
  }
};

int main() {
  ll N;
  string S;
  cin>>N>>S;
  int Q;
  cin>>Q;
  vector<int> D,M,C;
  vector<vector<ll>> cnt(N+1,vector<ll>(3,0));
  rep(i,N){
    if(S[i]=='D') {
      D.push_back(i);
      cnt[i+1][0]++;
    }
    if(S[i]=='M') {
      M.push_back(i);
      cnt[i+1][1]++;
    }
    if(S[i]=='C') {
      C.push_back(i);
      cnt[i+1][2]++;
    }
  }
  rep(i,N){
    rep(j,3){
      cnt[i+1][j]+=cnt[i][j];
    }
  }
  vector<ll> DMcnt(N+1,0);
  rep(i,N){
    if(S[i]=='M') DMcnt[i+1]+=cnt[i+1][0];
  }
  rep(i,N) DMcnt[i+1]+=DMcnt[i];
  rep(i,Q){
    int k;
    cin>>k;
    ll ans = 0;
    for(auto x:C){
      ll p = DMcnt[x+1]-DMcnt[max(0,x-k+1)]-cnt[max(0,x-k+1)][0]*(cnt[x+1][1]-cnt[max(0,x-k+1)][1]);
      ans += p;
    }
    cout<<ans<<endl;
  }
}