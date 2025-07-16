#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

/* short */
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)

/* REPmacro */
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)

/* exchange */
#define chmin(a, b) (a) = min((ll)(a), (ll)(b))
#define chmax(a, b) (a) = max((ll)(a), (ll)(b))

/* output */
#define I(x) cin >> x;
#define D(x) cerr << (x) << " ";
#define BR cerr << "\n";
#define P(x) cout << (x) << endl;
#define FIX cout << fixed << setprecision(10);

/* const */
const int ARRAY = 100005;
const int INF = 1001001001; // 10^9
const ll LINF = 1001001001001001001; // 10^18
const int MOD = 1e9 + 7;

ll N = 0;
ll Q;
ll ret = 0;

struct Event {
  ll t, type, X;
  bool operator<(const Event& a) {
    return t < a.t;
  }
};

vector<Event> eves;
multiset<ll> ms;

int main(void){
  
  I(N);
  I(Q);
  ll S, T, X;
  REP(i, N) {
    I(S);
    I(T);
    I(X);
    Event a = {S-X, 1, X};
    Event b = {T-X, -1, X};
    eves.pb(a);
    eves.pb(b);
  }
  sort(ALL(eves));

  ll d;
  ll k = 0;
  REP(i, Q) {
    I(d);
    while (k < eves.size() && eves[k].t <= d) {
      Event e = eves[k];
      if (e.type == 1) {
        ms.insert(e.X);
      } else {
        ms.erase(ms.find(e.X));
      }
      k++;
    }

    if (ms.empty()) {
      P(-1);
    } else {
      P(*ms.begin());
    }
    
  }
}
