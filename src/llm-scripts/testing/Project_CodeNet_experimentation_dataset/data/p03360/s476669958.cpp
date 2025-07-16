#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<long long> A(3);
  for (int i = 0; i < 3; ++i) cin >> A[i];
  long long K;
  cin >> K;
  sort(A.begin(), A.end());
  for (int i = 0; i < K; ++i) A.back() *= 2;
  cout << A[0] + A[1] + A[2] << endl;
}