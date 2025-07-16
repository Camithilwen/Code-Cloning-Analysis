#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, L;
  cin >> N >> L;
  vector<int> A;
  for (int i = 1; i <= N; i++) {
    A.push_back(L+i-1);
  }
  sort(A.begin(), A.end(), [](int x, int y) {
    return abs(x) < abs(y);
  });
  int total = 0;
  for (int i = 1; i < N; i++) {
    total += A[i];
  }
  cout << total << '\n';
  return 0;
}
