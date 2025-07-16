#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  vector<int64_t> M(N);
  for (int i = 0; i < N; i++) {
    int l = -1;
    int r = N;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (A.at(mid) < B.at(i)) {
        l = mid;
      }
      else {
        r = mid;
      }
    }
    M.at(i) = (l + 1);
  }
  int64_t ans = 0;
  for (int i = 0; i < N; i++) {
    int l = -1;
    int r = N;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (C.at(mid) > B.at(i)) {
        r = mid;
      }
      else {
        l = mid;
      }
    }
    ans += (M.at(i) * (N - r));
  }
  cout << ans << endl;
}