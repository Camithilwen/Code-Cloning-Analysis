#include<bits/stdc++.h>

#define oo ll(1e16)
#define maxn 200005
#define block 400

using namespace std;
typedef long long ll;

int n, q, a, b;
ll d[maxn];
ll L[maxn], R[maxn];

ll ret = 0;

ll get(int st, int en, int ok) {
  ll ret = oo;

  for (int i = st; i <= en;)
    if (i % block == 1 && i + block <= en + 1) {
      ret = min(ret, (ok ? L[(i - 1) / block] : R[(i - 1) / block]));
      i += block;
    }
    else {
      ret = min(ret, d[i] + (ok ? -i : i));
      ++i;
    }

  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);

  cin >> n >> q >> a >> b;

  fill(d + 1, d + n + 1, oo);
  fill(L, L + n + 1, oo);
  fill(R, R + n + 1, oo);

  d[b] = 0;
  L[(b - 1) / block] = -b;
  R[(b - 1) / block] = b;

  while (q--) {
    int x;
    cin >> x;

    ll tem = min(get(1, x, 1) + x, get(x, n, 0) - x);

    d[a] = min(d[a], tem - abs(x - a));

    int bl = (a - 1) / block;

    L[bl] = oo;
    R[bl] = oo;

    for (int i = max(bl * block + 1, 1); i <= bl * block + block && i <= n; ++i) {
      L[bl] = min(L[bl], d[i] - i);
      R[bl] = min(R[bl], d[i] + i);
    }

    ret += abs(x - a);

   // for (int i = 1; i <= n; ++i) cerr << d[i] + ret << ' '; cerr << "\n\n";

    a = x;
  }

  ll ma = 0;
  for (int i = 1; i <= n; ++i)
    ma = min(ma, d[i]);

  cout << ma + ret;

  return 0;

}
