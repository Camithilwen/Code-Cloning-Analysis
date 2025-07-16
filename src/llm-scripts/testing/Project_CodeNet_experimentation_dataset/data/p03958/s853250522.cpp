#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int k, t;
  cin >> k >> t;

  priority_queue<int> pq;
  rep(i, 0, t) {
    int a;
    cin >> a;
    pq.push(a);
  }

  int ans = 0;
  bool is_first = true, flg = false;
  rep(i, 0, k) {
    if (flg)
      ans++;
    if (pq.size() == 1)
      flg = true;

    if (is_first) {
      int a = pq.top();
      pq.pop();
      a--;
      if (a)
        pq.push(a);
    } else {
      int a = pq.top();
      pq.pop();
      if (!pq.empty()) {
        int b = pq.top();
        pq.pop();
        b--;
        if (b)
          pq.push(b);
      }
      pq.push(a);
    }
    is_first = !is_first;
  }

  cout << ans << endl;
}
