#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A);
  vector<int> b(B);
  for(int i = 0; i < A; i++) {
    cin >> a.at(i);
  }
  for(int i = 0; i < B; i++) {
    cin >> b.at(i);
  }
  int ans = 200000;
  for(int i = 0; i < M; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    if(a.at(x - 1) + b.at(y - 1) - c < ans) {
      ans = a.at(x - 1) + b.at(y - 1) - c;
    }
    if(i == M - 1) {
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      if(a.at(0) + b.at(0) < ans) {
        ans = a.at(0) + b.at(0);
      }
    }
  }
  cout << ans << endl;
}