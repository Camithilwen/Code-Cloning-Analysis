#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  int ans = 1e9;
  for (int i = 0; i < s.size() - 2; i++) {
    ans = min(ans, abs(753 - atoi((s.substr(i, 3)).c_str())));
  }
  cout << ans << endl;
  return 0;
}