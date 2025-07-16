#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  int n, m;
  cin >> n >> m;
  int s[m];
  char c[m];
  rep(i, m) { cin >> s[i] >> c[i]; }
  for (int i = 0; i < pow(10, n); i++) {
    string str = to_string(i);
    bool flag = true;
    rep(j, m) {
      if (str[s[j] - 1] != c[j]) {
        flag = false;
        break;
      }
    }
    if (flag && str.length() == n) {
      cout << str << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
}
