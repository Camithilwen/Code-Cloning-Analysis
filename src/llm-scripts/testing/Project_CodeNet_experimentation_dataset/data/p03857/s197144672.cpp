#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

#include <vector>
using namespace std;

/* Union-Find-Tree */
/* 必ず要素数をコンストラクタに入れること */
template <class T = long long>
class Union_Find {
  using size_type = std::size_t;
  using _Tp = T;
public:

  vector<_Tp> par;
  vector<_Tp> rnk;

  // 親の根を返す。値の変更は認めない。
  const _Tp & operator[] (size_type child) {
    find(child);
    return par[child];
  }

  Union_Find (_Tp n) {
    par.resize(n), rnk.resize(n);
    for (int i = 0; i < n; ++i) {
      par[i] = i;
      rnk[i] = 0;
    }
  }

  // 木の根を求める
  _Tp find(_Tp x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }

  // xとyの属する集合を併合
  void merge(_Tp x, _Tp y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rnk[x] < rnk[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rnk[x] == rnk[y]) rnk[x]++;
    }
  }

  // xとyが同じ集合に属するか否か
  bool same(_Tp x, _Tp y) {
    return find(x) == find(y);
  }
};


int main() {
  int n,k,l;
  cin >> n >> k >> l;
  Union_Find<long long> uf_road(n+1), uf_train(n+1);

  int r,s;
  rep(i,k) {
    cin >> r >> s;
    uf_road.merge(r, s);
  }

  rep(i,l) {
    cin >> r >> s;
    uf_train.merge(r, s);
  }

  vector<pair<int,int> > com;
  map<pair<int,int>, int> mp;

  for (int i = 1; i <= n; ++i) {
    int a, b;
    a = uf_road[i];
    b = uf_train[i];
    com.push_back(make_pair(a,b));
    mp[make_pair(a,b)] += 1;
  }

  for (int i = 0; i < n; ++i) {
    cout << mp[com[i]] << " ";
  }

  END;
}
