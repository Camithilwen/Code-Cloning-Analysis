#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;

  while (cin >> n) {

    n += ".";

    int num[] = {1, 5, 10, 50, 100, 500, 1000};
    char ch[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    int cnt = 0;
    vector<int> a;
    for (int i = 0; i < n.size(); ++i) {
      int x = 0;
      for (int j = 0; j < 7; ++j) {
        if (n[i] == ch[j]) x = num[j];
      }
      cnt += x;
      if (n[i] == n[i + 1]) continue;
      a.push_back(cnt);
      cnt = 0;
    }

    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] < a[i + 1]) a[i + 1] -= a[i];
      else ans += a[i];
    }

    cout << ans << endl;
  }
}