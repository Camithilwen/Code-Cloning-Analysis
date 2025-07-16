#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n, u, v;
  cin >> n >> u >> v;
  u--, v--;
  vector<vl> g(n);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<vl> d(2, vl(n, -1));
  rep(k, 2) {
    queue<ll> q;
    q.push(u);
    d[k][u] = 0;
    while(!q.empty()) {
      int i = q.front();
      q.pop();
      for(auto v : g[i]) {
        if(d[k][v] != -1) continue;
        d[k][v] = d[k][i] + 1;
        q.push(v);
      }
    }
    swap(u, v);
  }
  ll mx = 0;
  rep(i, n) if(d[0][i] < d[1][i]) mx = max(mx, d[1][i]);
  cout << mx - 1 << endl;
}