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

  sort(a.begin(), a.end());
  int ans = 0;
  int last = 0;
  int exist = 0;
  rep(i, n) {
    if (a[i] == last) exist = 1 - exist;
    else {
      ans += exist;
      last = a[i];
      exist = 1;
    }
  }
  ans += exist;
  cout << ans << endl;
  return 0;
}