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
const int INF = 1001001001;
const int MOD = 1000000007;

int dp[1000005][2];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   string s;
   cin >> s;
   reverse(s.begin(), s.end());
   s += '0';
   int n = s.size();
   rep(i, 0, n + 1) rep(j, 0, 2) dp[i][j] = INF;
   dp[0][0] = 0;
   rep(i, 0, n) rep(j, 0, 2) {
      int x = s[i] - '0';
      x += j;
      rep(a, 0, 10) {
         int ni = i + 1, nj = 0;
         int b = a - x;
         if (b < 0) {
            nj = 1;
            b += 10;
         }
         dp[ni][nj] = min(dp[ni][nj], dp[i][j] + a + b);
      }
   }
   int ans = dp[n][0];
   cout << ans << endl;
   return 0;
}