#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N, X;
  cin >> N >> X;
  vector<long long int> A(N);
  long long int ans = 0;
  for (long long int i = 0; i < N; i++) cin >> A.at(i);
  for (long long int i = 1; i < N; i++) {
    if (A.at(i) + A.at(i - 1) > X) {
      ans += A.at(i) + A.at(i - 1) - X;
      if (A.at(i - 1) > X) {
        A.at(i - 1) = X;
        A.at(i) = 0;
      }
      else {
        A.at(i) = X - A.at(i - 1);
      }
    }
  }
  cout << ans << endl;
}