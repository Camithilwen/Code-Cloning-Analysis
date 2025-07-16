#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Z algorithm O(|S|)
vector<int> Z_algorithm(vector<int> &s) {
  vector<int> Z(s.size());
  Z[0] = s.size();
  
  int i = 1, j = 0;
  while (i < s.size()) {
    while (i + j < s.size() && s[j] == s[i + j]) j++;
    Z[i] = j;
    if (j == 0) {
      i++;
      continue;
    }
    int k = 1;
    while (k < j && k + Z[k] < j) {
      Z[i + k] = Z[k];
      k++;
    }
    i += k;
    j -= k;
  }
  return Z;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  for (int i = 0; i < n; i++) cin >> b.at(i);
  
  vector<int> keep(n);
  for (int i = 0; i < 30; i++) {
    vector<int> x, y;
    for (int j = 0; j < n; j++) {
      if (b.at(j) & (1 << i)) {
        x.emplace_back(1);
        y.emplace_back(1);
      }
      else {
        x.emplace_back(0);
        y.emplace_back(0);
      }
    }
    for (int j = 0; j < n; j++) {
      if (a.at(j) & (1 << i)) {
        x.emplace_back(1);
        y.emplace_back(0);
      }
      else {
        x.emplace_back(0);
        y.emplace_back(1);
      }
    }
    for (int j = 0; j < n; j++) {
      if (a.at(j) & (1 << i)) {
        x.emplace_back(1);
        y.emplace_back(0);
      }
      else {
        x.emplace_back(0);
        y.emplace_back(1);
      }
    }
    vector<int> xret = Z_algorithm(x), yret = Z_algorithm(y);
    for (int j = n; j < 2 * n; j++) {
      if (xret.at(j) >= n || yret.at(j) >= n) keep.at(j - n)++;
    }
  }
  
  for (int i = 0; i < n; i++) {
    if (keep.at(i) == 30) {
      cout << i << " " << (a.at(i) ^ b.at(0)) << '\n';
    }
  }
}