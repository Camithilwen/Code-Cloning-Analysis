#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N, O = 0;
  cin >> N;
  for (ll i = 0; i <= N; i++) {
    if (i % 3 != 0 && i % 5 != 0) {O += i;}
  }
  cout << O << endl;
}