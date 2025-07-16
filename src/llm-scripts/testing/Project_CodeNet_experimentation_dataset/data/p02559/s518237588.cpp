
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;
// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
    //末尾の要素(i&-i)をたす→一つ上の階層なので、要素の更新の時に使える
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
     //末尾の要素(i&-i)を引く→一つ上の一つ左の階層なので、要素の総和をとる時に使える
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
    T sum(int l, int r) {
        return sum(r-1) - sum(l-1);
    }
};




int main() {
  ll n,q;
  cin>>n>>q;
  BIT <ll> B(n);
  vector<ll> a(n);
  rep(i,n){
    cin>>a[i];
    B.add(i,a[i]);
  }
  rep(i,q){
    ll t1,t2,t3;
    cin>>t1>>t2>>t3;
    if(t1==0){
      B.add(t2,t3);
    }
    else{

      ll ans=B.sum(t2,t3);
      cout<<ans<<endl;
    }

  }

}
