#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

template <class T>
struct prop_segtree {
  int n;
  vector<T> data;
  vector<bool> propFlag;

  prop_segtree(const int s) {
    init(s);
  }

  prop_segtree(const int s, const T u) {
    init(s);
    for (int i = 0; i < s; i++) {
      data[i+n-1] = u;
    }
    for (int i = n-2; i >= 0; i--) {
      data[i] = 0;
    }
  }

  prop_segtree(const vector<T> &v) {
    int s = v.size();
    init(s);
    for (int i = 0; i < s; i++) {
      data[i+n-1] = v[i];
    }
    for (int i = n-2; i >= 0; i--) {
      data[i] = 0;
    }
  }

  void init(const int s) {
    n = 1;
    while (n < s) n <<= 1;
    data = vector<T>(2*n-1);
    propFlag = vector<bool>(2*n-1);
  }

  void propagate(int p, int a, int b) {
    if (propFlag[p]) {
      if (b - a > 1) {
        data[p*2+1] = data[p];
        data[p*2+2] = data[p];
        propFlag[p*2+1] = true;
        propFlag[p*2+2] = true;
        data[p] = 0;
      }
      propFlag[p] = false;
    }
  }

  void update(int l, int r, T v, int p = 0, int a = 0, int b = -1) {
    if (b < 0) b = n; // init

    // propagate value
    propagate(p, a, b);

    if (r <= a || b <= l) return; // out of range
    if (l <= a && b <= r) { // fully covered
      data[p] = v;
      propFlag[p] = true;
      propagate(p, a, b);
    }
    else {
      update(l, r, v, p*2+1, a, (a + b) / 2); // left
      update(l, r, v, p*2+2, (a + b) / 2, b); // right
    }
    return;
  }

  T query(int x, T p = 0, int a = 0, int b = -1) {
    if (b < 0) b = n; // init

    // propagate value
    propagate(p, a, b);

    if (b - a == 1) return data[p];// reached to bottom

    if (x < (a + b) / 2) return query(x, p*2+1, a, (a + b) / 2); // left
    else return query(x, p*2+2, (a + b) / 2, b); // right
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  vector<vector<int> > query(q, vector<int>(4));
  for (int i = 0; i < q; i++) {
    cin >> query[i][0] >> query[i][1];
    if (query[i][0] == 0) cin  >> query[i][2] >> query[i][3];
  }

  prop_segtree<int> pst(n, 0x7fffffff);
  vector<ll> ans;
  for (int i = 0; i < q; i++) {
    if (query[i][0] == 0) { // update
      pst.update(query[i][1], query[i][2]+1, query[i][3]);
    }
    else { // get
      ans.push_back(pst.query(query[i][1]));
    }
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}

