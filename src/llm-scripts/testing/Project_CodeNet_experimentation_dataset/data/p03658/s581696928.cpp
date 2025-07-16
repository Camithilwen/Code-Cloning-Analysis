#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  rep(i, n) cin >> l[i];
  sort(l.begin(), l.end(), greater<int>());
  int ans = 0;
  rep(i, k) ans += l[i];
  cout << ans << endl;
  return 0;
}