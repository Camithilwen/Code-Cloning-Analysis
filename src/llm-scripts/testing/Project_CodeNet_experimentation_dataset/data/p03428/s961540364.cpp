#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n;
  cin >> n;
  vec x(n),y(n);
  for(ll i=0;i<n;i++) cin >> x[i] >> y[i];
  for(ll i=0;i<n;i++) {
    vector<double> d;
    for(ll j=0;j<n;j++) {
      if(i==j) continue;
      d.push_back(atan2(y[j]-y[i],x[j]-x[i]));
    }
    sort(d.begin(),d.end());
    double r=0;
    ll k=d.size();
    for(ll j=0;j<k;j++) {
      d.push_back(d[j]+2*M_PI);
    }
    for(ll j=0;j<k;j++) {
      r=max(r,M_PI-(d[j+k]-d[j+1]));
    }
    cout << fixed << setprecision(10) << r/(2*M_PI) << endl;
  }
}