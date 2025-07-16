#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> E(N + 1), W(N + 1);
  for (int i = 1; i < N + 1; i++) {
    E.at(i) = E.at(i - 1) + (S.at(i - 1) == 'E');
    W.at(i) = W.at(i - 1) + (S.at(i - 1) == 'W');
  }
  int ans = 2e9;
  for (int i = 0; i < N + 1; i++) {
    ans = min(ans, E.at(N) - E.at(i) + W.at(i));
  }
  cout << ans << "\n";
}