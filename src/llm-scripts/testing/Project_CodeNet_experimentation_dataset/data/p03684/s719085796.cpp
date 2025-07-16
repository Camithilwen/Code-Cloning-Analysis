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

class UF {

  vector<int> par; // 親
  vector<int> rank; // 深さ

public:

  void init(int n) { // n個で初期化
    for(int i=0;i<n;i++) {
      par.push_back(i);
      rank.push_back(0);
    }
  }

  UF(int n) {
    for(int i=0;i<n;i++) {
      par.push_back(i);
      rank.push_back(0);
    }
  }

  int find(int x) { // 木の中のxの深さを返す
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  void unite(int x, int y) { // xとyを統合する
    x = find(x);
    y = find(y);
    if (x == y) return;

    if(rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) { // xとyが等しいかどうか判定する
    return find(x) == find(y);
  }
};

struct Edge {
  int from, to, cost;
};

bool operator<(const Edge& e1, const Edge& e2) {
  return e1.cost > e2.cost;
}

struct Point {
  int pos, x, y;
};

bool operator<(const Point& p1, const Point& p2) {
  return p1.x < p2.x;
}

bool operator>(const Point& p1, const Point& p2) {
  return p1.y < p2.y;
}

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i] << " ";
  }
  cout << endl;
}

int main () {
  cin.tie(0);
  cout << setprecision(10);

  int n; cin >> n;
  vector<Point> p(n);
  REP(i, n) {
    p[i].pos = i;
    cin >> p[i].x >> p[i].y;
  }

  vector<vector<Edge>> g(n);
  
  sort(ALL(p));
  REP(i, n-1) {
    Edge e;
    int cost = min(abs(p[i].x - p[i+1].x), abs(p[i].y - p[i+1].y));
    e.from = p[i].pos;
    e.to = p[i+1].pos;
    e.cost = cost;
    g[e.from].pb(e);
    swap(e.from, e.to);
    g[e.from].pb(e);
  }

  sort(ALL(p), greater<Point>());
  REP(i, n-1) {
    Edge e;
    int cost = min(abs(p[i].x - p[i+1].x), abs(p[i].y - p[i+1].y));
    e.from = p[i].pos;
    e.to = p[i+1].pos;
    e.cost = cost;
    g[e.from].pb(e);
    swap(e.from, e.to);
    g[e.from].pb(e);
  }

  UF uf(n);

  ll ans = 0;
  int cnt = 0;
  priority_queue<Edge> edges;
  REP(i, SZ(g[0])) {
    edges.push(g[0][i]);
  }
  
  while(cnt < n-1) {
    Edge next = edges.top(); edges.pop();
    if(!uf.same(next.from, next.to)) {
      uf.unite(next.from, next.to);
      ans += next.cost;
      cnt++;
      REP(i, SZ(g[next.to])) {
        edges.push(g[next.to][i]);
      }
    }
  }

  cout << ans << endl;
  
}
