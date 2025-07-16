#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long l[n];
  for (int i = 0; i < n; ++i) cin >> l[i];
  sort(l, l + n);

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (l[i] == l[j]) continue;
      for (int k = j + 1; k < n; ++k) {
        if (l[i] == l[k] || l[j] == l[k]) continue;
        if (l[i] + l[j] <= l[k]) break;
        cnt++;
      }
    }
  }

  cout << cnt << endl;
}
