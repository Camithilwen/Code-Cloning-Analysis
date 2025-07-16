#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
        #define eprintf(...) 42
#endif

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define foreach(u,v) for(auto (u) : (v))
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

const int inf = 1e9;
const ll linf = 1LL<<60;
const ll mod = 1e9 + 7;
const double eps = 1e-9;

/*
*/

typedef tuple<int, int, int> triple;

int n, m;
map<pii, vector<triple>> g;
map<pii, ll> dist;

int main()
{
  cin >> n >> m;
  rep(i, m){
    int p, q, c;
    cin >> p >> q >> c;
    p--; q--;

    g[mp(p, c)].pb(mt(q, c, 0));
    g[mp(q, c)].pb(mt(p, c, 0));
    g[mp(p, c)].pb(mt(q, -1, 0));
    g[mp(q, c)].pb(mt(p, -1, 0));
    g[mp(p, -1)].pb(mt(q, c, 1));
    g[mp(q, -1)].pb(mt(p, c, 1));

    dist[mp(p, c)] = linf;
    dist[mp(q, c)] = linf;
    dist[mp(p, -1)] = linf;
    dist[mp(q, -1)] = linf;
  }
  
  rep(i, n) dist[mp(i, -1)] = linf;

  priority_queue<triple, vector<triple>, greater<triple>> que;
  que.push(mt(0, 0, -1));
  dist[mp(0, -1)] = 0;

  while(!que.empty()){
    int d, v, c;
    tie(d, v, c) = que.top();
    que.pop();

    if(dist[mp(v, c)] < d) continue;
    for(auto e : g[mp(v, c)]){
      int to, cc, dd;
      tie(to, cc, dd) = e;
      if(dist[mp(to, cc)] > dist[mp(v, c)] + dd){
        dist[mp(to, cc)] = dist[mp(v, c)] + dd;
        que.push(mt(dist[mp(to, cc)], to, cc));
      }
    }
  }
  
  ll ans = dist[mp(n-1, -1)];
  if(ans == linf) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}
