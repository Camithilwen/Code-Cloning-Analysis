#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int ans = 1e9;
  rep(i, n) {
    int c = 0;
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      c++;
    }
    ans = min(ans, c);
  }
  cout << ans << endl;
  return 0;
}