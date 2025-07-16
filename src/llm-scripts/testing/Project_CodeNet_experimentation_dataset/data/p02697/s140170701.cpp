// review
#include <iostream>

using namespace std;

int n, m;

void solve() {
  int second = m & 1 ? m + 1 : m + 2;
  int cnt = 1;
  int cnt2 = 0;
  for (int i=0;i<m;i++) {
    if (i < m / 2) {
      cout << cnt << " " << (second - cnt) << endl;
      cnt++;
    } else {
      cout << cnt2 + second << " " << (2 * m + 1 - cnt2) << endl;
      cnt2++;
    }
  }
}

int main() {
  cin >> n >> m;
  solve();
}
