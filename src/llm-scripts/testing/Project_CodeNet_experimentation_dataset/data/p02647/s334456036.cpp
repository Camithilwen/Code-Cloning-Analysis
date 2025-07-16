#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  for (int i = 0; i < k && i*i < n; i++) {
    vector<int> imos(n+1);
    rep(j, n) {
      imos[max(j-a[j], 0)]++;
      imos[min(j+a[j]+1, n)]--;
    }
    rep(j, n)
      imos[j+1] += imos[j];
    a = imos;
  }
  rep(i, n) {
    if (i)
      cout << ' ';
    cout << a[i];
  }
  cout << endl;
  return 0;
}