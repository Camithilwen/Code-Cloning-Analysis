#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b; cin >> a >> b;
  int n = 0;
  while (1) {
    if ((a-1) * n + 1 >= b) break;
    n++;
  }
  cout << n << endl;
  return 0;
}