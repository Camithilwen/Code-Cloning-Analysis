#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, dig = 0;

  cin >> n >> k;

  int d;
  for (int i = 0; i < k; i++) {
    cin >> d;
    dig |= 1 << d;
  }

  for (int i = n; ; i++) {
    string num = to_string(i);
    bool bad = false;
    for (auto c : num)
      if (dig & (1 << (c - '0'))) {
        bad = true;
        break;
      }

    if (!bad) {
      cout << num << endl;
      break;
    }
  }

  return 0;
}