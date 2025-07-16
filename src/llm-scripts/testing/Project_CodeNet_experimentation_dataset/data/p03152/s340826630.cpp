#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(X, i) ((X>>i)&1)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define r_all(a) (a).rbegin(), (a).rend()
#define in(x) cin>>x
#define ina(x, n) rep(x_i,n) cin>>x[x_i]
#define outa(x, n) rep(x_i,n) cout<<x[x_i]<<"\t\n"[x_i==n-1]

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef priority_queue<ll> pq;

const int MOD = 1e9+7;
const int INF = (1<<30);
const ll INFL = (1L<<62);

int main() {
  ll n, m; cin >> n >> m;
  vl a(n), b(m); ina(a,n); ina(b,m);
  sort(all(a)); sort(all(b));
  rep(i,n-1) if (a[i]==a[i+1]) { puts("0"); return 0; }
  rep(i,m-1) if (b[i]==b[i+1]) { puts("0"); return 0; }
  ll ans = 1;
  for (ll now = n*m; now > 0; now--) {
    auto ita = lower_bound(all(a), now);
    auto itb = lower_bound(all(b), now);
    int st = (*ita == now) + (*itb == now);
    if (st == 0) {
      ans *= (a.end() - ita)*(b.end() - itb) - (n*m - now);
    }
    if (st == 1 && *ita == now) {
      ans *= (b.end() - itb);
    }
    if (st == 1 && *itb == now) {
      ans *= (a.end() - ita);
    }
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
