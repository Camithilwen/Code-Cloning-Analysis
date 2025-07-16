#include <assert.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cout << i << "\n"

// const ll MOD = 998244353;
const ll MOD = 1000000007;

// UnionFind
template<class T>
struct UnionFind {
  std::vector<T> uni;
  T num;
  UnionFind(T s) : uni(s, -1), num(s) {}

  //頂点aが所属するグループ
  T root(T a) {
    if (uni[a] < 0) {
      return a;
    }
    return uni[a] = root(uni[a]);
  }

  // a,bをつなげる
  bool connect(T a, T b) {
    a = root(a);
    b = root(b);
    if (a == b) {
      return false;
    }

    if (uni[a] > uni[b]) {
      std::swap(a, b);
    }

    uni[a] += uni[b];
    uni[b] = a;
    return true;
  }

  // a,bが同グループか確認
  bool isConnect(T a, T b) { return root(a) == root(b); }

  // aが属するグループの要素数
  T size(T a) { return -uni[root(a)]; }

  //グループ数を返す
  T groups() {
    std::set<T> b;
    for (T i = 0; i < num; i++) {
      b.insert(root(i));
    }
    return b.size();
  }
};

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n,k,l;
  std::cin>>n>>k>>l;
  UnionFind<int> load(n),rail(n);
  rep(i,0,k){
    ll a,b;
    std::cin>>a>>b;
    a--;b--;
    load.connect(a,b);
  }
  rep(i,0,l){
    ll a,b;
    std::cin>>a>>b;
    a--;b--;
    rail.connect(a,b);
  }
  std::vector<P> temp1(n),temp2(n);
  rep(i,0,n){
    temp1[i]=P(load.root(i),rail.root(i));
    temp2[i]=P(load.root(i),rail.root(i));
  }
  sort(all(temp1));
  rep(i,0,n){
    auto low=std::lower_bound(all(temp1),temp2[i]);
    auto up=std::upper_bound(all(temp1),temp2[i]);
    std::cout<<up-low<<" ";
  }
  return 0;
}