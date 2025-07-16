#include "bits/stdc++.h"

using ll = long long;

using namespace std;
// #include "debug.h"
#define debug(...) 42

const int mod = 998244353;

void solve() {
   int n;
   cin >> n;
   vector <int> d(n), cnt(n);
   for(int i = 0; i < n; i++) {
      cin >> d[i];
      cnt[d[i]]++;
   }
   bool ok = true;
   ok &= d[0] == 0;
   ok &= cnt[0] == 1;

   if(!ok) {
      cout << 0 << endl;
      return;
   }
   int m = *max_element(d.begin(), d.end());

   ll ans = 1;
   for(int i = 1; i <= m; i++) {
      if(cnt[i] == 0) {
         cout << 0 << endl;
         return;
      }
      for(int j = 0; j < cnt[i]; j++) {
         ans = (ans * 1LL * cnt[i - 1]) % mod;
      }
   }

   cout << ans << endl;
} 

signed main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   int testcase = 1;
   // cin >> testcase;

   for(int i = 0; i < testcase; i++) {
      solve();
   }
   return 0;
}
