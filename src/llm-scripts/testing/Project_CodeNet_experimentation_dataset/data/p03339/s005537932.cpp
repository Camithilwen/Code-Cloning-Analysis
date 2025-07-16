#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int N;
  string v;
  cin >> N >> v;
  vector<int> e(N+1, 0);
  vector<int> w(N+1, 0);
  REP(i, N) {
    if (v[i] == 'W') {
      w[i+1] = w[i] + 1;
      e[i+1] = e[i];
    } else {
      e[i+1] = e[i] + 1;
      w[i+1] = w[i];
    }
  }

  int ans = N;
  
  for(int i = 1; i <= N; i++) {
    if (i == 0) {
      ans = min(ans, e[N] - e[i]);
    } else if (i == N) {
      ans = min(ans, w[N-1]);
    } else {
      ans = min(ans, w[i-1] + (e[N] - e[i]));
    }
  }
  cout << ans << endl;

  return 0;
}