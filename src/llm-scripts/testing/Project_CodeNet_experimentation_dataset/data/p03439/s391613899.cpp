#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  scanf("%d", &n);
  int l = 0, r = n;
  printf("%d\n", l);
  fflush(stdout);
  string sl;
  cin >> sl;
  while (sl != "Vacant") {
    int m = (l + r) / 2;
    printf("%d\n", m);
    fflush(stdout);
    string sm;
    cin >> sm;
    if (sm == "Vacant" || l % 2 == m % 2 && sl == sm || l % 2 != m % 2 && sl != sm) {
      l = m;
      sl = sm;
    } else {
      r = m;
    }
  }
  printf("%d\n", l);
  fflush(stdout);
  return 0;
}