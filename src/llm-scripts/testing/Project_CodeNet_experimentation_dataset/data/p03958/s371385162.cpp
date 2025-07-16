#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

const int N = 123;

int a[N];

void solve() {
  int k, t; scanf("%d%d", &k, &t);
  for (int i = 0; i < t; ++i) scanf("%d", a+i);
  if (t == 1) {
    printf("%d", a[0]-1);
    return;
  } 
  sort(a, a+t);
  int spare = 1;
  int prev = 0;
  for (int i = 0; i < t-1; ++i) {
    if (i && a[i] == a[i-1]) continue;
    spare += (a[i]-prev)*(t-i-2);
    a[t-1] -= (a[i]-prev);
    prev = a[i];
  }
  printf("%d", max(a[t-1]-spare, 0));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
