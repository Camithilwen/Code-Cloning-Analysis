#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); ++i)
#define repf(i, from, to) for (int i = (from); i < (to); ++i)
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;

int main() {
  int n;
  V<int> a;
  map<int, int> count;
  cin >> n;
  a.resize(n);
  rep(i, n) {
    cin >> a[i];

    count[a[i]] = 0;
  }

  // Count
  rep(i, n) {
    count[a[i]]++;
  }
  // Aggregate
  int ans = 0;
  for(auto it = count.begin(); it != count.end(); it++) {
    if(it->second % 2 == 1) {
      ans++;
    }
  }

  cout << ans << endl;
}