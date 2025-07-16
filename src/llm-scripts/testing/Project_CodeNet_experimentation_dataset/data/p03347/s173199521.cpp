#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
using lli = long long int;
template <typename T>
vector<T> read_vector(int n) {
  vector<T> result(n);
  for (auto& a : result) cin >> a;
  return result;
}
template <typename T>
vector<T> read_vector() {
  int n;
  cin >> n;
  return read_vector<T>(n);
}

int main() {
  ios_base::sync_with_stdio(false);
  auto v = read_vector<int>();
  bool valid = v[0] == 0;
  for (int i = 1; i < v.size(); ++i) valid &= v[i] <= v[i - 1] + 1;
  if (!valid) {
    cout << -1;
    return 0;
  }
  lli cost = 0;
  int prev = 0;
  reverse(all(v));
  for (auto a : v) {
    prev = max(0, prev - 1);
    if (a < prev) {
      cout << -1;
      return 0;
    } else if (a > prev) {
      cost += a;
    }
    prev = a;
  }
  cout << cost;
  return 0;
}