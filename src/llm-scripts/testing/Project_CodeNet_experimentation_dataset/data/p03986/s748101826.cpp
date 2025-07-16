#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  string s;
  cin >> s;
  int ans = s.size(), cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'S') cnt++;
    else {
      if (cnt) {
        ans -= 2;
        cnt--;
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
