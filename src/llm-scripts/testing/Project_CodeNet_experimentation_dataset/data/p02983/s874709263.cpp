#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  ll L, R;
  cin >> L >> R;
  /*
  ll sa = R - L;
  L %= 2019;
  R %= 2019;
  if (L == 0 || L == 2018) cout << 0 << endl;
  else if (sa < 2019 - L) cout << (L * (L + 1)) % 2019 << endl;
  else cout << 0 << endl;
  */
  int ans = 2018;
  R = min(R, L + 4038);
  for (ll i = L; i <= R; i++){
    for (ll j = i + 1; j <= R; j++){
      int x = i*j%2019;
      ans = min(ans, x);
    }
  }
  cout << ans << endl;
  return 0;
}
