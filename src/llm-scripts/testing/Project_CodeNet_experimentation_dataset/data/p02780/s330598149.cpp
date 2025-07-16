#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int64_t N, K;
  cin >> N >> K;
  vector<int> p(N);
  vector<double> memo(N + 1);
  memo.at(0) = 0;
  for (int64_t i = 0; i < N; i++) {
    cin >> p.at(i);
    memo.at(i + 1) = (memo.at(i) + ((p.at(i) + 1) / 2.0));
  }
  double ans = 0;
  for (int64_t i = 0; i <= N - K; i++) {
    double M = (memo.at(i + K) - memo.at(i));
    ans = max(M, ans);
  }
  cout << fixed << setprecision(16);
  cout << ans << endl;
}
    