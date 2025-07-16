#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A);
  for (int i = 0; i < A; i++) cin >> a.at(i);
  vector<int> b(B);
  for (int i = 0; i < B; i++) cin >> b.at(i);

  int ans = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
  
  for (int i = 0; i < M; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    ans = min(ans, a.at(x - 1) + b.at(y - 1) - c);
  }

  cout << ans << "\n";
}