#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

const ll N=2e5+50;
vec l(N),r(N);
vec a(N);

ll cal(ll x) {
  if(x<3) {
    return 0;
  }
  return max({l[x-1],r[x-1],cal(x-2)+a[x]});
}

int main() {
  ll n;
  cin >> n;
  for(ll i=1;i<=n;i++) cin >> a[i];
  for(ll i=2;i<=n;i+=2) {
    l[i]=l[i-2]+a[i-1];
    r[i]=max(r[i-2],l[i-2])+a[i];
  }
  if(n%2) {
    cout << cal(n) << endl;
  }
  else {
    cout << max(l[n],r[n]) << endl;
  }
}