#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
//#define __DEBUG__
#ifdef __DEBUG__
#define CH_P(a) cout <<"check_point("<<#a<<")" << "\n";
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#endif
#ifndef __DEBUG__
#define CH_P(a) 
#define DEBUG(x) 
#define DEBUGS(v) 
#endif
/* clang-format on */

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  string s;
  cin >> s;
  ll n = s.size();
  ll ans = 1 + (n * (n - 1)) / 2;
  REP(a, 26) {
    ll cnt = 0;
    REP(i, n) {if (s[i] == 'a' + a) cnt++; }
    ans -= cnt * (cnt - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
