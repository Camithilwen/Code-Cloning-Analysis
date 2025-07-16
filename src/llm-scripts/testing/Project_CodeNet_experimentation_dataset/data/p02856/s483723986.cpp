#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  ll m;
  cin >> m;
  ll n=0;
  ll d=0;
  for(ll i=0;i<m;i++) {
    ll tc,td;
    cin >> td >> tc;
    n+=tc;
    d+=td*tc;
  }
  cout << n-1+(d-1)/9 << endl;
}