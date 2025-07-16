#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cn(n + 1, 0);
  rep(i, n) cin >> a[i];
  cn[0] = 3;
  ll ans = 1;
  rep(i, n){
    if(cn[a[i]] <= 0){
      cout << 0 << endl;
      return 0;
    }
    ans *= cn[a[i]];
    ans %= MOD;
    cn[a[i]]--;
    cn[a[i] + 1]++;
  }
  cout << ans << endl;
}