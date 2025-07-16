#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

typedef pair<int, int> P;
int N;
vector<int> A;
const int MONOID = 0;
ll f(ll x, ll y) {
  return x + y;
}

void add(ll x, ll y) {
  ll i = x + N - 1;
  A.at(i) += y;
  while (i > 0) {
    i = (i-1)/2;
    A.at(i) = f(A.at(i*2+1), A.at(i*2+2));
  }
}

ll findRec(ll x, ll y, ll n, ll l, ll r) {
  if (r <= x || y <= l) return MONOID;
  if (x <= l && r <= y) return A.at(n);
  return f(
    findRec(x, y, n*2+1, l, (l+r)/2),
    findRec(x, y, n*2+2, (l+r)/2, r)
  );
}

ll find(ll x, ll y) {
  return findRec(x, y+1, 0, 0, N);
}

int main() {
  int n,q; cin >> n >> q;
  N = 1;
  while (N < n) N *= 2;
  vector<int> C(n);
  A.assign(3*n, 0);
  loop(i,0,n) cin >> C[i];

  vector<int> points[n+1];
  vector<int> prev(n+1, -1);
  loop(i,0,n) {
    int c = C[i];
    if (prev[c] != -1) {
      points[prev[c]].emplace_back(i);
    }
    prev[c] = i;
  }

  vector<P> qs[n+1];
  loop(i,0,q) {
    int l,r;cin >> l >> r;
    l--;r--;
    qs[l].emplace_back(r, i);
  }

  vector<int> ans(q, 0);
  for (int x=n-1; x>=0; x--) {
    for (auto &&y: points[x]) {
      add(y, 1);
    }
    for (auto q: qs[x]) {
      ans[q.second] = q.first-x+1-find(0, q.first);
    }
  }
  loop(i,0,q) cout << ans[i] << endl;
  return 0;
}
