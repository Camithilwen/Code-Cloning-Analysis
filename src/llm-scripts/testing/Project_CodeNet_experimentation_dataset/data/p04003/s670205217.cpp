#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

struct edge { 
  ll to; ll d;
  bool operator< (const edge &x) const { return to<x.to; }
};
map<ll, set<edge>> adj;

map<ll, ll> dijkstra(int n=0) {
  auto c = [](const p_ll &x, const p_ll &y){return x.second>y.second;};
  priority_queue<p_ll, vector<p_ll>, decltype(c)> q(c);
  map<ll, ll> result; result[n] = 0; q.push(make_pair(n,0));
  while(q.size()) {
    p_ll now = q.top(); q.pop();
    ll np = now.first, nd = now.second;
    if (nd>result[np]) continue;
    for (auto x: adj[np]) {
      if (result.count(x.to)&&result[x.to]<=result[np]+x.d) continue;
      q.push(make_pair(x.to, result[np]+x.d));
      result[x.to] = result[np]+x.d;
    }
  }
  return result;
}

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

ll C = pow(10,6)+10;

int main() {
  int N, M; cin >> N >> M;
  rep(i,M) {
    ll p, q, c; cin >> p >> q >> c; p--; q--;
    adj[p*C].insert({p*C+c,1}); adj[p*C+c].insert({p*C,0});
    adj[q*C].insert({q*C+c,1}); adj[q*C+c].insert({q*C,0});
    adj[p*C+c].insert({q*C+c,0}); adj[q*C+c].insert({p*C+c,0});
  }
  map<ll, ll> d = dijkstra();
  // for (auto x: d) cout << x.first << "->" << x.second << " "; cout << endl;
  ll result = d.count((N-1)*C) ? d[(N-1)*C] : -1;
  cout << result << endl;
  return 0;
}