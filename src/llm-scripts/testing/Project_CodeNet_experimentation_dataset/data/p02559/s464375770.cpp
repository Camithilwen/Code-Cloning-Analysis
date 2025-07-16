#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
using namespace atcoder;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, Q; cin >> N >> Q;
  fenwick_tree<ll> ft(N);
  REP(i, N){
    ll a; cin >> a;
    ft.add(i, a);
  }
  REP(i, Q){
    int q; cin >> q;
    if(q == 0){
      int p; ll x; cin >> p >> x;
      ft.add(p, x);
    }else{
      int l, r; cin >> l >> r;
      ll ans = ft.sum(l, r);
      cout << ans << endl;
    }
  }
}