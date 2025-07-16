#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;

bool rec(int n, vector<int>& num, vector<bool>& isPlus) {
  // ベースケース
  if (n == (int) isPlus.size()) {
    int ans = num[0];
    rep(i, (int) isPlus.size()) {
      if (isPlus[i]) {
        ans += num[i + 1];
      } else {
        ans -= num[i + 1];
      }
    }

    if (ans == 7) {
      cout << num[0];
      rep(i, (int) isPlus.size()) {
        if (isPlus[i]) {
          cout << '+' << num[i + 1];
        } else {
          cout << '-' << num[i + 1];
        }
      }
      cout << "=7" << endl;
      return true;
    }

    return false;
  }

  // 再帰ステップ
  isPlus[n] = true;
  if (rec(n + 1, num, isPlus)) return true;
  isPlus[n] = false;
  if (rec(n + 1, num, isPlus)) return true;

  return false;
}


int main(void) {
  int ABCD;
  cin >> ABCD;
  vector<int> num(4);
  rep(i, 4) {
    num[i] = ABCD % 10;
    ABCD /= 10;
  }

  reverse(num.begin(), num.end());

  vector<bool> isPlus(3, true);
  rec(0, num, isPlus);
  
  return 0;
}