#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  if (N == 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> ans(0);
  while (N != 0) {
    int tmp = N % 2;
    if (tmp < 0) tmp += 2;
    N = (N-tmp) / (-2);
    ans.push_back(tmp);
  }
  for (int i = ans.size()-1; i >= 0; i--) cout << ans[i];
  cout << endl;
}
