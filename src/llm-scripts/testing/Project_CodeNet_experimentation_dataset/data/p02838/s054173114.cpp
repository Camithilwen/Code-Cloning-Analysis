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

int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n;
   cin >> n;
   vector<ll> a(n);
   rep(i, 0, n) cin >> a[i];

   ll ans = 0;
   rep(i, 0, 60) {
      ll x = 0;
      rep(j, 0, n) {
         if (a[j] >> i & 1) x++;
      }
      ll now = x * (n - x) % MOD;
      rep(j, 0, i)(now *= 2) %= MOD;
      (ans += now) %= MOD;
   }
   cout << ans << endl;
   return 0;
}