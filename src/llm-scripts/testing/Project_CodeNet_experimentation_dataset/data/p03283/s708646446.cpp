#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

template<typename T>
struct BIT{
  int n;
  vector<T> d;
  BIT(int n = 0):n(n),d(n+1){}
  void add(int i,T x=1){
    for(i++;i<=n;i += i&-i){
      d[i] += x;
    }
  }
  T sum(int i){
    T x = 0;
    for(i++;i>0;i -= i&-i){
      x += d[i];
    }
    return x;
  }
};

int main(){
  int n,m,q;cin >> n >> m >> q;
  vector<P> sche(m);
  vector<pair<P,int>> query(q);
  rep(i,m){
    int l,r;cin >> l >> r;
    sche[i] = make_pair(l,r);
  }
  sort(sche.rbegin(),sche.rend());
  vector<int> ans(q);
  rep(i,q){
    int p,q;cin >> p >> q;
    P temp = make_pair(p,q);
    query[i] = make_pair(temp,i);
  }
  sort(query.rbegin(),query.rend());
  int inds = 0;
  int indq = 0;
  BIT<int> tree(505);
  for(int x = n;x >= 0;x--){
    while(inds < m && sche[inds].first >= x) {
      tree.add(sche[inds].second,1);
      inds++;
    }

    while(indq < q && query[indq].first.first >= x){
      ans[query[indq].second] += tree.sum(query[indq].first.second);
      indq++;
    }
  }

  rep(i,q) cout << ans[i] << endl;
}