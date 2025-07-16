#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define MAX 500005
//#define INF 1001001001

template <typename T>
struct RMQ {
  const T INF = numeric_limits<T>::max();
  int n;
  vector<T> dat, lazy;
  RMQ(int _n) : n(), dat(_n*4,INF), lazy(_n*4,INF) {
    int x = 1;
    while (x < _n) x <<= 1;
    n = x;
  }

  void update(int i, T x) {
    i += n-1;
    dat[i] = x;
    while (i > 0) {
      i = (i-1)/2;
      dat[i] = min(dat[i*2+1],dat[i*2+2]);
    }
  }

  T query(int a, int b, int k, int l, int r) {
    eval(k);
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return dat[k];
    T mid = (l+r)>>1;
    T vl = query(a,b,k*2+1,l,mid);
    T vr = query(a,b,k*2+2,mid,r);
    return min(vl,vr);
  }
  T query(int a, int b) { return query(a,b,0,0,n); }

  void eval(int k) {
    if (lazy[k] == INF) return;
    if (k < n-1) lazy[k*2+1] = lazy[k*2+2] = lazy[k];
    dat[k] = lazy[k];
    lazy[k] = INF;
  }

  void update(int a, int b, int x, int k, int l, int r) {
    eval(k);
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      lazy[k] = x;
      eval(k);
    } else {
      int mid = (l+r)>>1;
      update(a,b,x,k*2+1,l,mid);
      update(a,b,x,k*2+2,mid,r);
      dat[k] = min(dat[k*2+1],dat[k*2+2]);
    }
  }
  void update(int a, int b, int x) { update(a,b,x,0,0,n); }

  inline T operator[](int a) { return query(a,a+1); }
};

int main(int, char**)
{
  int n, q;
  cin >> n >> q;
  RMQ<int> rmq(n);

  vector<int> ans;
  rep(i,q) {
    int command; cin >> command;
    if (command == 0) {
      int s, t, x;
      cin >> s >> t >> x;
      rmq.update(s,t+1,x);
    } else if (command == 1) {
      int i; cin >> i;
      ans.push_back(rmq[i]);
    }
  }
  for (auto a : ans) cout << a << endl;

  return 0;
}

