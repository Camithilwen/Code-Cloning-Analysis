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

int p;

bool check(int x) {
  cout << x << endl;
  string s; cin >> s;
  if (s == "Vacant") exit(0);
  if (x%2 == p && s == "Male") return true;
  if (x%2 != p && s == "Female") return true;
  return false;
}

void solve() {
  string s; int n;
  cin >> n;
  cout << 0 << endl;
  cin >> s;
  if (s == "Vacant") return;
  if (s == "Female") p = 1;
  int lo = 0, hi = n;
  while (lo+1 < hi) {
    int mid = (lo+hi)/2;
    if (check(mid)) lo = mid;
    else hi = mid;
  }
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
