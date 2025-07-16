#include <bits/stdc++.h>
using namespace std;

bool isprime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 2; v.size() < n; ++i)
    if (isprime(i) && i % 5 == 1) v.push_back(i);
  for (int i = 0; i < n; ++i) {
    cout << v[i];
    if (i == n - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}
