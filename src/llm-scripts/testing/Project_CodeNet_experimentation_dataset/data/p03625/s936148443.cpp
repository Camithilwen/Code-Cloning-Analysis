#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x] += 1;
  }
  vector<int> ans;
  for (auto p : mp) {
    if (p.second >= 4) {
      ans.push_back(p.first);
      ans.push_back(p.first);
    } else if (p.second >= 2) {
      ans.push_back(p.first);
    }
  }
  sort(ans.begin(), ans.end(), greater<int>());
  if (ans.size() < 2) {
    cout << 0 << endl;
  } else {
    cout << 1LL * ans[0] * ans[1] << endl;
  }
  return 0;
}
