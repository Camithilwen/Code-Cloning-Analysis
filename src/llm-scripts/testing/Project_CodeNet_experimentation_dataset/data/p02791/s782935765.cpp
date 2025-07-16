#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
class SegTree {
  constexpr static int DEFAULT = INT_MAX;
  int Combine(int l, int r) { return min(l,r); }

  vector<int> seg_tree;
  int n = 0;

  void Build(vector<int>& A, int v, int tl, int tr) {
    if (tl == tr) {
      seg_tree[v] = A[tl];
    } else {
      int tm = tl + (tr - tl) / 2;
      Build(A, v*2, tl, tm);
      Build(A, v*2+1, tm+1, tr);
      seg_tree[v] = Combine(seg_tree[v*2], seg_tree[v*2+1]);
    } 
  }
 public:

  SegTree(vector<int>& A) {
    n = A.size();
    seg_tree.resize(4*n);
    Build(A, 1, 0, n-1);
  }

  SegTree(int _n) : n(_n) {
    //seg_tree.resize(4*n);
    seg_tree.resize(4*n, DEFAULT);
  }

  int Query(int l, int r, int tl, int tr, int v) {
    if (l > r) return DEFAULT;
    if (l == tl && r == tr) return seg_tree[v];
    int tm = tl + (tr - tl) / 2;
    return Combine(Query(l, min(r, tm), tl, tm, v*2), 
                   Query(max(l, tm+1), r, tm+1, tr, v*2+1));
  }

  int Query(int l, int r) {
    return Query(l, r, 0, n-1, 1);
  }

  void Update(int pos, int new_val, int tl, int tr, int v) {
    if (tl == tr) {
      seg_tree[v] = new_val;
      return;
    }

    int tm = tl + (tr - tl) / 2;
    if (pos <= tm) {
      Update(pos, new_val, tl, tm, v*2);
    } else {
      Update(pos, new_val, tm+1, tr, v*2+1);
    }
    seg_tree[v] = Combine(seg_tree[v*2], seg_tree[v*2+1]);
  }

  void Update(int pos, int new_val) {
    Update(pos, new_val, 0, n-1, 1);
  }
};

 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n;
  cin >> n;
  vector<int> A(n);
  for (auto& _a : A) cin >> _a;
  SegTree stree(A);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (stree.Query(0, i) == A[i]) ++ans;
  }
  cout << ans << endl;
  

}
