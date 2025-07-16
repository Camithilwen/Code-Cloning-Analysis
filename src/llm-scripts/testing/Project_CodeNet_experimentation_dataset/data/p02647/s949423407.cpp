#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < K; i++) {
    vector<int> B(N+1, 0);
    for (int j = 0; j < N; j++) {
      int left = max(0, j - A.at(j));
      int right = min(N, j + A.at(j) + 1);
      B.at(left)++; B.at(right)--;
    }
    for (int j = 0; j < N; j++) B.at(j+1) += B.at(j);
    B.pop_back();
    if (A == B) break;
    A = B;
  }
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << A.at(i);
  }
  cout << endl;
}