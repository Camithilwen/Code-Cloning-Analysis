#include <bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  int odd = 0;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    odd += a[i] & 1;
  }
  if (odd > 2) {
    cout << "Impossible\n";
    return 0;
  }
  for (int i = 0; i < m && odd > 0; i++) {
    if (a[i] & 1) {
      swap(a[i], a[0]);
      odd--;
      break;
    }
  }
  for (int i = m - 1; i >= 0 && odd > 0; i--) {
    if (a[i] & 1) {
      swap(a[i], a[m - 1]);
      odd--;
      break;
    }
  }
  for (int i = 0; i < m; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  vector<int> b;
  for (int i = 0; i < m; i++) {
    b.push_back(a[i] + (i == 0 ? -1 : (i == m - 1 ? 1 : 0)));
  }
  if (m == 1) {
    b.push_back(1);
  }
  cout << (int) b.size() - (b[0] == 0) << '\n';
  for (int i = (b[0] == 0); i < (int) b.size(); i++) {
    cout << b[i] << ' ';
  }
  cout << '\n';
  return 0;
}