#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
  string abcd;
  cin >> abcd;

  rep(i, 1<<3) {
    bitset<3> bit(i);
    int sum = abcd[0] - '0';
    string ans = "";
    ans += abcd[0];
    rep(j, 3) {
      if (bit[j] == 0) {
        sum += abcd[j+1] - '0';
        ans += "+";
        ans += abcd[j+1];
      }
      else {
        sum -= abcd[j+1] - '0';
        ans += "-";
        ans += abcd[j+1];
      }
    }
    if (sum == 7) {
      ans += "=7";
      cout << ans << endl;
      return 0;
    }
  }
}
