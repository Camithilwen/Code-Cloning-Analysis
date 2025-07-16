#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n;
  cin >> n;
  vector<ll> a;
  ll cnt = 0;
  if (n == 0) {
    cout << 0 << '\n';
    return 0;
  }
  for (ll i = 0; n != 0; i++) {
    a.push_back(n % -2);
    if (a[i] == -1) {
      a[i] = 1;
      n = (n-1)/-2;
    }  
    else n = n / -2;
    ++cnt;
  }
  rep(i,cnt) cout << a[cnt-i-1];
  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}