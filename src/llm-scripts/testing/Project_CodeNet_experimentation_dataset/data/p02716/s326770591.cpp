#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
   if (a > b) {
      a = b;
      return true;
   }
   return false;
}
template <class T>
inline bool chmax(T& a, T b) {
   if (a < b) {
      a = b;
      return true;
   }
   return false;
}
void hr() {
   cerr << "--------------" << endl;
}
const ll INF = 1e18;
const int MOD = 1000000007;
// const int MOD = 998244353;

ll dp[200005][5];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n;
   cin >> n;
   vector<int> a(n);
   rep(i, 0, n) cin >> a[i];
   int k = 1 + n % 2;
   rep(i, 0, n + 1) rep(j, 0, k + 1) dp[i][j] = -INF;
   dp[0][0] = 0;
   rep(i, 0, n) {
      rep(j, 0, k + 1) {
         chmax(dp[i + 1][j + 1], dp[i][j]);
         ll now = dp[i][j];
         if ((i + j) % 2 == 0) now += a[i];
         chmax(dp[i + 1][j], now);
      }
   }
   ll ans = dp[n][k];
   cout << ans << endl;
   return 0;
}