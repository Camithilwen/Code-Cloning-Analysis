#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  int t[N];
  for (int i=0; i<N; i++)
    cin >> t[i];
  long ans = 0, start = t[0], prev = t[0];
  for (int i=1; i<N; i++) {
    if (t[i]>prev+T) {
      ans += prev+T-start;
      start = t[i];
    }
    prev = t[i];
  }
  ans += prev+T-start;
  cout << ans << endl;
  return 0;
}