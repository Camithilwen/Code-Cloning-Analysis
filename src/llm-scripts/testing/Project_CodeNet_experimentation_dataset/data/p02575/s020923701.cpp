/*
 * @Author: Kaizyn
 * @Date: 2020-08-29 19:57:44
 * @LastEditTime: 2020-08-30 10:24:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int INF = 0x3f3f3f3f;

struct SegmentTree {
  struct TreeNode {
    int l, r, v, lazy;
  } tr[N<<2];
  void push_down(int i) {
    if (!tr[i].lazy) return;
    tr[i<<1].lazy = tr[i<<1|1].lazy = tr[i].lazy;
    tr[i<<1].v = tr[i<<1].l-tr[i].lazy;
    tr[i<<1|1].v = tr[i<<1|1].l-tr[i].lazy;
    tr[i].lazy = 0;
  }
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r;
    if (l == r) return;
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void update(int l, int r, int k, int i = 1) {
    if (l <= tr[i].l && r >= tr[i].r) {
      tr[i].v = tr[i].l-k;
      tr[i].lazy = k;
      return;
    }
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) update(l, r, k, i<<1);
    if (r >  mid) update(l, r, k, i<<1|1);
    tr[i].v = min(tr[i<<1].v, tr[i<<1|1].v);
  }
  int query(int x, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].l-tr[i].v;
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) return query(x, i<<1);
    else return query(x, i<<1|1);
  }
};

int n, m;
SegmentTree seg;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  seg.build(1, m);
  for (int i = 1, l, r; i <= n; ++i) {
    cin >> l >> r;
    if (l == 1) seg.update(l, r, -INF);
    else seg.update(l, r, seg.query(l-1));
    cout << (seg.tr[1].v > m ? -1 : seg.tr[1].v+i) << endl;
  }
  return 0;
}