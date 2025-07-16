#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
string s;
int dp[2][3][300004];

void sub(const string& s) {
  dp[1][0][0] = 1;
  for (int i = 1; i < s.size(); ++i) {
    for (int c : {0, 1}) {
      if (c == 1 && s[i] == '0'
       || c == 0 && s[i] == '1') continue;
      for (int pc : {0, 1}) {
        for (int k : {0, 1, 2}) {
          int nk =
            k == 2 ? 2
          : k == 1 ? (i % 2 == 0 && c == 1 && pc == 1 ? 2 : 1)
          :          (i % 2 == 1 && c == 1 && pc == 1 ? 1 : 0);
          dp[c][nk][i] += dp[pc][k][i - 1];
          if (dp[c][nk][i] >= mod) dp[c][nk][i] -= mod;
        }
      }
    }
  }
}

int main() {
  cin >> s;
  s = '1' + s + '1';
  sub(s);
  const int n = s.size();
  cout << dp[1][2][n - 1] << endl;
}
