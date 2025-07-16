#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  string s, t; cin >> s >> t;
  for(int i=n; i>=0; i--) {
    string s_ = s.substr(n-i);
    string t_ = t.substr(0, i);
    if(s_ == t_) {
      cout << n*2-i << "\n";
      break;
    }
  }
  return 0;
}
