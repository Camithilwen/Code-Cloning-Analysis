// ref. https://img.atcoder.jp/dwacon5th-prelims/editorial.pdf

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <set>

using namespace std;

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

template<class T> void printvec(const vector<T>& v) {
  for (auto x : v) { cout << x << " "; }
  cout << endl;
}
template<class T> void printtree(const vector< vector<T> >& tree) {
  for (long long i = 0; i < tree.size(); ++i) {
    cout << i + 1 << ": "; printvec(tree[i]);
  }
}
template<class T, class U> void printmap(const map<T, U>& mp) {
  for (auto x : mp) { cout << x.first << "=>" << x.second << endl; }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define rep(i, n) for(ll i = 0; i < n; ++i)
#define all(s) s.begin(), s.end()
#define fr first
#define sc second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> triple;
typedef double D;

const ll INF = 1e9;
const ll MOD = 1000000007;  // 1e9 + 7

ll n;
string s;

ll solve(ll k) {
  ll d_cnt = 0, m_cnt = 0;
  ll now = 0; // current contribution
  ll ans = 0;
  rep(i, n) {
    // At first, decrease from i-k
    if (i >= k) {
      char target = s[i-k];
      if (target == 'D') {
        --d_cnt;
        now -= m_cnt; // decrease contribution by this D
      } else if (target == 'M') {
        --m_cnt;
      } else {
        // Do nothing
      }
    }

    // Next, add contribution from i
    if (s[i] == 'D') {
      ++d_cnt;
    } else if (s[i] == 'M') {
      ++m_cnt;
      now += d_cnt; // increase contribution by this M
      // cout << "d_cnt:" << d_cnt << endl;
    } else if (s[i] == 'C') {
      // cout << "now:" << now << endl;
      ans += now;
    }
  }
  return ans;
}

int main(int argc, char** argv) {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  //cout << setprecision(10) << fixed;

  cin >> n;
  cin >> s;
  ll q;
  cin >> q;
  rep(iter, q) {
    ll k;
    cin >> k;
    ll ans = solve(k);
    cout << ans << endl;
  }
}
