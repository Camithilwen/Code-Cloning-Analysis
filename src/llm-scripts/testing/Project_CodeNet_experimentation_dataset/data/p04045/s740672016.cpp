#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> d(k,0);
  rep(i,k) cin >> d[i];

  while(1){
    bool flag = false;
    rep(i,k){
      string s = to_string(n);
      rep(j,s.size()) {
        if ((int)s[j] - (int)'0' == d[i]) {
          n++;
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) {
      cout << n << endl;
      return 0;
    }
  }
}