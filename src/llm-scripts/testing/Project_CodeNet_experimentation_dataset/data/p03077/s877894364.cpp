#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  ll n,a,b,c,d,e;
  cin >> n >> a >> b >> c >> d >> e;
  ll mn= min(min(min(a,b),c),min(d,e));
  ll ans = (n-0.5)/mn +5;
  cout << ans << endl; 
  return 0;
}