#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  string s;
  cin >> n >> s;
  ll r = 0, b = 0, g = 0;
  rep(i, n) {
    if (s.at(i) == 'R') {
      r++;
      continue;
    }
    if (s.at(i) == 'G') {
      g++;
      continue;
    }
    if (s.at(i) == 'B') {
      b++;
      continue;
    }
  }
  ll ans = r * b * g;
  if (!ans) {
    cout << 0 << endl;
    return 0;
  }
  rep(i, n) {
    reps(j, i+1, n) {
      if (s.at(i) == s.at(j)) continue;

      int k = 2*j - i;
      if (k >= n) continue;
      if ((s.at(i) != s.at(j)) && (s.at(i) != s.at(k)) && (s.at(k) != s.at(j))) {
        ans--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}