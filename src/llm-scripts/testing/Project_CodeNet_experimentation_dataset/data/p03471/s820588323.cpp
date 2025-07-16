#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, y;
  cin >> n >> y;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; i + j <= n; ++j) {
      int k = n - i - j;
      if (10000 * i + 5000 * j + 1000 * k == y) {
        printf("%d %d %d\n", i, j, k);
        return 0;
      }
    }
  }
  printf("-1 -1 -1\n");
  return 0;
}