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

   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   rep(i, 0, n) cin >> a[i];

   int ans = 0;
   rep(l, 0, k + 1) rep(r, 0, k - l + 1) {
      if (l + r > n) continue;
      int d = k - l - r;
      int now = 0;
      vector<int> s;
      rep(i, 0, l) {
         now += a[i];
         s.push_back(a[i]);
      }
      rep(i, n - r, n) {
         now += a[i];
         s.push_back(a[i]);
      }
      sort(s.begin(), s.end());
      rep(i, 0, d) {
         if (i >= s.size()) break;
         if (s[i] >= 0) break;
         now -= s[i];
      }
      ans = max(ans, now);
   }
   cout << ans << endl;
   return 0;
}