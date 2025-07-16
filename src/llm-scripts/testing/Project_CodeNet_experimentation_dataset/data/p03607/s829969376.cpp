#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  set<int> hako;
  map<int, int> s;

  for (int i = 0; i < n; i++) {
    s[a[i]]++;
  }

  for (auto it = s.begin(); it != s.end(); it++) {
    if ((it->second % 2) != 0) {
      ans++;
    }
  }
  cout << ans << endl;
}