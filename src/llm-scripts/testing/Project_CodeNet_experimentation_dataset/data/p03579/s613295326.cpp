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

int col[100005];
graph g;
bool color(int x){
  bool ok = true;
  for(auto nx:g[x]){
    if(col[nx]!=-1) {
      if(col[nx]==col[x]) ok = false;
      else continue;
    }
    else {
      col[nx] = 1-col[x];
      if(!color(nx)) ok = false;
    }
  }
  return ok;
}

int main() {
  ll N,M;
  cin>>N>>M;
  g.resize(N);
  rep(i,100005) col[i] = -1;
  col[0]=0;
  rep(i,M){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  bool can = color(0);
  if(!can) cout<<N*(N-1)/2-M<<endl;
  else{
    ll cnt0 = 0,cnt1 = 0;
    rep(i,N) {
      if(col[i]==0) cnt0++;
      if(col[i]==1) cnt1++;
    }
    cout<<cnt0*cnt1-M<<endl;
  }
}