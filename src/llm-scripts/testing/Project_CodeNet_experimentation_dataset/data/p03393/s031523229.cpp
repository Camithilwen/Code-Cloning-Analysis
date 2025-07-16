#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

/* Macros reg. ends here */

const ll INF = 1LL << 50;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  string s;
  cin >> s;

  set<ll> mi;
  rep(i, 26) mi.insert(i);

  ll n = s.size();
  string ans = "";
  rep(i, n) {
    ll idx = s[i] - 'a';
    if (mi.find(idx) != mi.end()) {
      mi.erase(idx);
      ans += s[i];
    } else {
      auto citr = mi.begin();
      ans += *citr + 'a';
      mi.erase(citr);
    }
  }  // i

  if (s == ans) {
    if (!mi.empty()) {
      rep(i, 26) {}
      ans += *mi.begin() + 'a';
    } else {
      vector<char> tst;
      rep(i, 26) tst.push_back(s[i]);
      next_permutation(tst.begin(), tst.end());
      string cmp = "";
      for (char c : tst) cmp += c;
      if (cmp < s) {
        puts("-1");
        return 0;
      } else {
        rep(i,26) if(ans[i] != cmp[i]){
          ans = cmp.substr(0, i+1);
          break;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
