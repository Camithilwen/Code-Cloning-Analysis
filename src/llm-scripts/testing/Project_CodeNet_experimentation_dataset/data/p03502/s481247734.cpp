#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int f(int n) {
  int ret = 0;
  while (n >= 1) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  if (n % f(n) == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}