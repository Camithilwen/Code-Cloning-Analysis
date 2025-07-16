#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long N, Q;
  string S;
  cin >> N >> S >> Q;
  vector<int> k(Q);
  for (int i = 0; i < Q; i++) {
    cin >> k[i];
  }
  for (int j = 0; j < Q; j++) {
    long long d = 0, m = 0, dm = 0, ans = 0;
    for (int i = 0; i < N; i++) {
      if (i >= k[j]) {
        if (S[i - k[j]] == 'D') {
          d--;
          dm -= m;
        }
        if (S[i - k[j]] == 'M') m--;
      }

      if (S[i] == 'D') d++;
      if (S[i] == 'M') {
        m++;
        dm += d;
      }
      if (S[i] == 'C') {
        ans += dm;
      }
    }
    cout << ans << endl;
  }

  return 0;
}