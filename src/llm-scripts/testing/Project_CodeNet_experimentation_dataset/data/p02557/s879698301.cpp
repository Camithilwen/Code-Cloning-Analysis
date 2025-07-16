#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector A(N, 0), B(N, 0);
  for (auto &a : A) cin >> a;
  for (auto &a : B) cin >> a;

  auto f = [&]() {
    for (int i = N - 1; i >= 0; i--) {
      if (A.at(i) == B.at(i)) return false;
    }
    cout << "Yes" << "\n";
    for (auto ans : B) cout << ans << "\n";
    return true;
  };

  reverse(B.begin(), B.end());
  if (f()) return 0;
  reverse(B.begin(), B.end());

  rotate(B.begin(), B.begin() + (N / 2), B.end());
  if (f()) return 0; 
  cout << "No" << "\n";
}