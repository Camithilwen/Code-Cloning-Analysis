#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;
typedef pair<ll, ll> P;

vector<ll> G[1000], Ginv[1000];
vector<P> ps;


int main() {
  ll N, M; cin >> N >> M;
  for (ll i = 0; i < M; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    G[a].push_back(b); Ginv[b].push_back(a);
    ps.push_back(P(a,b));
  }
  ll shortest = INF;
  vector<ll> res;

  for (ll i = 0; i < M; i++) {
    ll s = ps[i].second; ll t = ps[i].first;
    ll d[N];
    for (ll j = 0; j < N; j++) {d[j] = INF;}
    d[s] = 0;
    
    queue<ll> que; que.push(s);
    while (!que.empty()) {
      ll p = que.front(); que.pop();
      if (p == t) break;
      for (ll j = 0; j < G[p].size(); j++) {
        ll to = G[p][j];
        if (d[to] == INF) {que.push(to); d[to] = d[p]+1;}
      }
    }
    
    if (d[t]+1 < shortest) {
      ll p = t; res.push_back(p);
      while (d[p] > 0) {
        for (ll j = 0; j < Ginv[p].size(); j++) {
          ll to = Ginv[p][j];
          if (d[to]+1 == d[p]) {
            p = to; res.push_back(p); break;
          }
        }
      }
    }
    shortest = min(d[t]+1, shortest);
  }
  if (shortest == INF) {cout << -1 << endl; return 0;}
  cout << shortest << endl;
  ll n = res.size();
  for (ll i = n-1; i >= n-shortest; i--) {
    cout << res[i]+1 << endl;
  }
}