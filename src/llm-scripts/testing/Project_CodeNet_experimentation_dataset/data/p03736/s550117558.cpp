#include<bits/stdc++.h>
#define int long long
#define out(x) cerr << #x << " = " << x << "\n"
using namespace std;
// by piano
template<typename tp> inline void read(tp &x) {
  x = 0;char c = getchar();bool f = 0;
  for(; c < '0' || c > '9'; f |= (c == '-'), c = getchar());
  for(; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
  if(f) x = -x;
}
#define c(a, b) memset(a, b, sizeof(a))
const int N = 6e5 + 233;
int inf;
int n, Q, x, y, a[N], ans, tag, res[N];
#define root 1, n, 1
struct T {
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l) + (((r) - (l)) >> 1))
  int tr[N << 2], tag[N << 2];
  inline void init() {
    memset(tr, 1, sizeof(tr));
    inf = tr[0] + 233;
    memset(tag, 0, sizeof(tag));
  }
  inline void pd(int rt, int l, int r) {
    if(tag[rt]) {
      tr[ls] += tag[rt];
      tr[rs] += tag[rt];
      tag[ls] += tag[rt];
      tag[rs] += tag[rt];
      tag[rt] = 0;
    }
  }
	
  inline void A(int L, int R, int C, int l, int r, int rt) {
    if(L <= l && r <= R) {
      tr[rt] += C;
      tag[rt] += C;
      return ;
    }pd(rt, l, r);
    if(L <= mid) A(L, R, C, l, mid, ls);
    if(R > mid) A(L, R, C, mid + 1, r, rs);
    tr[rt] = min(tr[ls], tr[rs]);
  }
  inline void in(int L, int C, int l, int r, int rt) {
    int num = q(L, L, root);
    // cout << L << " " << C << " " << num << " in\n";
    A(L, L, C - num, root);
    // cout << q(L, L, root) << "\n";
    num = q(L, L, root);
    // cout << L << " " << C << " " << num << " in\n";
    A(L, L, C - num, root);
    // cout << q(L, L, root) << "\n";
    // puts("------");
  }
  inline int q(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return tr[rt];
    pd(rt, l, r);
    int ans = inf;
    if(L <= mid) ans = min(ans, q(L, R, l, mid, ls));
    if(R > mid) ans = min(ans, q(L, R, mid + 1, r, rs));
    return ans;
  }
}tr1, tr2;

inline void add2(int pos, int now) {
  now += (n - (pos - 1));
  tr2.in(pos, now, root);
} 

inline void add1(int pos, int now) {
  now += pos; 
  tr1.in(pos, now, root);
}

inline void solve(int pos, int pre) {
  // for(int i = 1; i <= n; i ++)
  //   cout << tr2.q(i, i, root)  << " ";
  // putchar('\n');
  // for(int i = 1; i <= n; i ++)
  //   cout << tr2.q(i, 6, root) << "  a";
  // putchar('\n');
  
  
  // for(int i = 1; i <= n; i ++)
  //   if(tr1.q(i, i, root) - i < 23333)
  //     cout <<tr1.q(i, i, root) - i << " is " << i << ", ";
  // puts("");
  int l = tr2.q(1, pos, root), r = tr1.q(pos + 1, n, root);
  l -= (n - (pos - 1)); r -= pos;
  // cout  << l << " " << r << "\n";
  int now = min(l, r);
  tr1.A(1, n, abs(pos - pre), root);
  tr2.A(1, n, abs(pos - pre), root);
  add1(pre, now);
  add2(pre, now);
  
  
//   for(int i = 1; i <= n; i ++)
//     if(tr1.q(i, i, root) - i < 23333)
//       cout <<tr1.q(i, i, root) - i << " is " << i << ", ";
//   puts("");
// }
}

main() {
  read(n); read(Q); read(x); read(y);
  tr1.init(); tr2.init();
  add1(y, 0); add2(y, 0);
  a[0] = x;
  for(int i = 1; i <= Q; i ++) read(a[i]);
  for(int i = 1; i <= Q; i ++) solve(a[i], a[i - 1]);
  ans = inf;
  // for(int i = 1; i <= n; i ++)
  //   cout << tr1.q(i, i, root) - i << " ";
  for(int i = 1; i <= n; i ++) {
    res[i] = tr1.q(i, i, root) - i;
    ans = min(ans, res[i]);
  }
  cout << ans  << "\n";
}
