#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  string s, t;
  cin >> N >> s >> t;
  for(int l=N; l<=2*N; l++) {
    string S(l, ' ');
    rep(i, N) S[i] = s[i];
    bool ok = true;
    rep(i, N) if(S[l-N+i] != ' ' && S[l-N+i] != t[i]) ok = false;
    if(ok) {
      cout << l << "\n";
      return 0;
    }
  }
  return 0;
}
