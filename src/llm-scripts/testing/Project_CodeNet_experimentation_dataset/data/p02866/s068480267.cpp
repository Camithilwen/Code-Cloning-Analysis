#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> D(N), cnt(N);
  for (int i = 0, d; cin >> d; i++) {
    D.at(i) = d;
    cnt.at(d)++;
  }
  if (D.at(0) || cnt.at(0) != 1) return cout << 0 << "\n", 0;
  long ans = 1;
  int mx = *max_element(D.begin(), D.end());
  for (long i = 1; i <= mx; i++) {
    long tmp = cnt.at(i);
    while (tmp--) {
      ans *= cnt.at(i - 1);
      ans %= 998244353;
    }
  }
  cout << ans << "\n";
}