#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) stable_sort(a.begin(), a.end())
#define rsort(a) stable_sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0LL)
#define join(a, d) accumulate(a.begin() + 1, a.end(), a[0], [](string s, string t) {return s + d + t;})
#define all(a) a.begin(), a.end()
// #define __lcm(a, b) std::__detail::__lcm(a, b)
typedef long long ll;
const long mod = 1e9 + 7;

ll lcm(ll x, ll y) {
    return x / __gcd(x, y) * y;
}

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  long N, K;
  cin >> N >> K;
  vector<long> A(N);
  rep(i, 0, N) cin >> A[i];
  long maxa = accumulate(all(A), A[0], [](long x, long y) {return max(x, y);});
  if (maxa < K) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  long gcd1 = accumulate(all(A), A[0], [](long x, long y) {return __gcd(x, y);});
  long gcd2 = __gcd(gcd1, K);
  if (gcd1 == gcd2) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
