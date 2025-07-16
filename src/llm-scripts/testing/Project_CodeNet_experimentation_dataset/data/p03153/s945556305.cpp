#include <bits/stdc++.h>

#define mp make_pair

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef pair<int,int> pii;
typedef pair<i64,int> pli;
typedef pair<int,i64> pil;
typedef pair<i64,i64> pll;
typedef vector<int> vi;
typedef vector<i64> vl;

template <typename T>
T id(T b) {return b;};
template <class It>
bool all(It f,It l){return std::all_of(f,l,id<bool>);}
template <class It>
bool any(It f,It l){return std::any_of(f,l,id<bool>);}

template <int N> class rmq {
  int n; i64 dat[4*N-1];
  i64 query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return dat[k];
    else {
      return min(query(a,b,2*k+1,l,(l+r)/2),query(a,b,2*k+2,(l+r)/2,r));
    }
  }

public:
  const i64 INF = INT64_MAX;
  rmq() {
    n = 1;
    while (n < N) n *= 2;
    for (int i = 0; i < 2*n-1; i++) dat[i] = INF;
  }

  void update(int k, i64 a) {
    k += n-1; dat[k] = a;
    while (k > 0) {
      k = (k-1) / 2;
      dat[k] = min(dat[2*k+1],dat[2*k+2]);
    }
  }

  i64 query(int a, int b) { return query(a, b, 0, 0, n); }
};

struct union_find {
  typedef vector<int> vi;
  vi parent,rank,cnt;
  int n;

  union_find(int n) : n(n) {
    parent = vi(n); rank = vi(n,0); cnt = vi(n,1);
    for (int i = 0; i < n; i++) parent[i] = i;
  }

  int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
  }

  void unite(int a, int b) {
    a = find(a); b = find(b);

    if (a == b) return;
    if (rank[a] < rank[b]) {
      parent[a] = b; cnt[b] += cnt[a];
    } else {
      parent[b] = a; cnt[a] = cnt[b];
      if (rank[a] == rank[b])
        rank[a]++;
    }
  }

  int count(int a) { return cnt[find(a)]; }

  bool same(int a, int b) { return find(a) == find(b); }
};

typedef tuple<i64,int,int> edge;

const int MAX_N = 200000;
int n;
i64 d, a[MAX_N];
pii b[MAX_N];
int tab[MAX_N];
rmq<MAX_N> r1, r2;
map<i64,int> m;

int main()
{
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> a[i], b[i] = mp(a[i],i);
  sort(b,b+n);

  for (int i = 0; i < n; i++) tab[b[i].second] = i;

  vector<edge> es;

  r1.update(tab[0], a[0]-d);
  m[a[0]-d] = 0;
  for (int i = 1; i < n; i++) {
    i64 v = r1.query(0,tab[i]);
    if (v < r1.INF) {
      int j = m[v];
      es.push_back(make_tuple(v+a[i]+(i+1)*d,i,j));
    }
    v = a[i]-(i+1)*d;
    r1.update(tab[i], v);
    m[v] = i;
  }

  m.clear();
  r2.update(tab[n-1], a[n-1]+n*d);
  m[a[n-1]+n*d] = n-1;
  for (int i = n-2; i >= 0; i--) {
    i64 v = r2.query(0,tab[i]);
    if (v < r2.INF) {
      int j = m[v];
      es.push_back(make_tuple(v+a[i]-(i+1)*d,i,j));
    }
    v = a[i]+(i+1)*d;
    r2.update(tab[i], v);
    m[v] = i;
  }

  sort(es.begin(),es.end());

  union_find uf(n);
  i64 res = 0;
  for (auto e : es) {
    i64 cost; int u,v;
    tie(cost,u,v) = e;
    if (uf.same(u,v)) continue;
    res += cost;
    uf.unite(u,v);
  }

  cout << res << endl;

  return 0;
}
