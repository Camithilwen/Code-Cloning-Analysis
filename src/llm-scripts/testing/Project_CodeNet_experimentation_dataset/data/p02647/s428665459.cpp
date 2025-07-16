#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  while (K--) {
    vector<int> V(N);
    for (int i = 0; i < N; i++) {
      V.at(max(0, i - A.at(i)))++;
      if (i + A.at(i) + 1 < N) V.at(i + A.at(i) + 1)--;
    }
    for (int i = 1; i < N; i++) V.at(i) += V.at(i - 1);
    if (A == V) break;
    A = V;
  }
  for (auto a : A) cout << a << "\n";
}