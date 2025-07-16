#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1000000007;
const int BASE = 27;
const int oo = 1e9;
const double EPS = 1e-9;
const int MX = 2e5 + 1;

int n;
ll  x;
struct exam {
  ll b, u, v;
};
exam e[MX];


struct line {
  ll a, b, idx;
  line() {
    a = b = idx = 0;
  }
  line(ll _a, ll _b, int _idx) {
    a = _a, b = _b, idx = _idx;
  }
  ll eval(ll x) {
    return a * x + b;
  }
  bool operator<( line &rhs) {
    if(eval(x) == rhs.eval(x))
      return a < rhs.a;
    return eval(x) < rhs.eval(x);
  }
};


bool check(ll rem) {
  vector<line> all;
  ll sc = 0;
  for (int i = 1; i <= n; ++i) {
    sc -= e[i].u * e[i].b;
    ll a1 = e[i].v;
    ll b1 = -e[i].b * (e[i].v - e[i].u);
    all.push_back(line(a1, b1, i));
  }
  if(sc == 0)return true;
  if(rem == 0)return false;
  sort(all.begin(),all.end());
  ll g1 = rem/x,g2;
  if(rem%x == 0)
    g2 = x,g1--;
  else g2 = rem%x;
  ll sm = 0;
  for(int j = all.size()-1;j>= all.size()-g1;--j)
    sm += all[j].eval(x);

  for(int j = all.size()-g1; j < all.size();++j){
    ll nwSm = sm-all[j].eval(x)+all[all.size()-g1-1].eval(x);
    ll mx = max(all[j].eval(g2),line(e[all[j].idx].u,0,all[j].idx).eval(g2));
    if(mx+nwSm+sc >= 0)
      return true;
    
  }
  for(int j = 0 ; j+g1 < all.size();++j){
    ll mx = max(all[j].eval(g2),
      line(e[all[j].idx].u,0,all[j].idx).eval(g2));
    if(mx+sm+sc >= 0)return true;
  }
  return false;
}

int main() {
  cin >> n >> x;
  for (int b, l, u, i = 1; i <= n; ++i) {
    scanf("%lld%lld%lld", &e[i].b, &e[i].u, &e[i].v);
  }

  ll lo = 0 , hi = 1ll * n * x, best = -1;
  while (lo <= hi) {
    ll md = (lo + hi) / 2;
    if (check(md)) {
      best = md;
      hi = md - 1;
    } else {
      lo = md + 1;
    }
  }
  cout << best << endl;
  return 0;
}
