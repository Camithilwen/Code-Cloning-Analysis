#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  int mi = sum;
  for (int i = 0; i < n; ++i) mi = min(mi, abs(sum - n * a[i]));

  for (int i = 0; i < n; ++i) {
    if (abs(sum - n * a[i]) == mi) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}
