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

void solve() {
  int primes[] = {3, 13, 23, 43, 53, 73, 83, 103, 113, 163, 173, 193, 223, 233, 263, 283, 293, 313, 353, 373, 383, 433, 443, 463, 503, 523, 563, 593, 613, 643, 653, 673, 683, 733, 743, 773, 823, 853, 863, 883, 953, 983, 1013, 1033, 1063, 1093, 1103, 1123, 1153, 1163, 1193, 1213, 1223, 1283, 1303};
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    printf("%d ", primes[i]);
  } 
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
