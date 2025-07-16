#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) RFOR(i, n, 0)
#define MFOR(i, m) for(auto i=(m).begin();i!=(m).end();i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1 << 30;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i] << " ";
  }
  cout << endl;
}

struct Plant {
  string l;
  int p, a, b, c, d, e, f, s, m;

  Plant(string l, int p, int a, int b, int c, int d, int e, int f, int s, int m) {
    this->l = l;
    this->p = p;
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->e = e;
    this->f = f;
    this->s = s;
    this->m = m;
  }

  int time() {
    return a + b + c + d + e + (m-1) * (d + e);
  }

  int benefit() {
    return f * s * m - p;
  }
};

static bool operator< (Plant &p1, Plant &p2) {
  if(p1.benefit() * p2.time() == p2.benefit() * p1.time()) {
    return p1.l < p2.l;
  } else {
    return p1.benefit() * p2.time() > p2.benefit() * p1.time();
  }
}

int main () {
  cin.tie(0);
  cout << setprecision(10);

  while(1) {
    int n; cin >> n;
    if(n == 0) break;
    vector<Plant> plants;
    REP(i, n) {
      string l; cin >> l;
      int p, a, b, c, d, e, f, s, m; cin >> p >> a >> b >> c >> d >> e >> f >> s >> m;
      plants.pb(Plant(l, p, a, b, c, d, e, f, s, m));
    }
    sort(ALL(plants));
    REP(i, n) {
      cout << plants[i].l << endl;
    }
    cout << "#" << endl;
  }
}

