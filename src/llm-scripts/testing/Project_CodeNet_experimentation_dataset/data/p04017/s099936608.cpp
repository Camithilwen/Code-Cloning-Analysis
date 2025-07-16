#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<ll>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)cin >> a[i];
  ll l; cin >> l;
  int ln = log2(n);
  Graph next (ln+ 1, vector<ll>(n));
  for(int i = 0; i < n; ++i){
    int idx= upper_bound(a.begin(),a.end(), a[i]+l)-a.begin();
    next[0][i] = idx-1;
    //cout << next[0][i] << endl;
  }
  
  for(int k = 0; k < ln; ++k){
    for(int i = 0; i < n; ++i){
      next[k+1][i] = next[k][next[k][i]];
    }
  }
  int Q;cin >> Q;
  for(int _ = 0; _ < Q; ++_){
    int a,b;cin >> a >> b;
    --a;--b;
    if(a>b)swap(a,b);
    int lb = -1, ub = n;
    while(ub-lb>1){
      int mb = (ub+lb)/2;
      int now = a;
      for(int i = ln; i >= 0; --i){
        if((mb>>i)&1){
          now = next[i][now];
        }
      }
      if(now>=b)ub = mb;
      else lb = mb;
    }
    cout << ub << endl;
  }
}
