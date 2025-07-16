#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  vector<ll> p(5);
  rep(i,5) cin >> p.at(i);

  ll mi = p.at(0);
  rep(i,5) mi = min(mi, p.at(i));

  ll ans = ceil(double(n/double(mi))) + 4;
  cout << ans;
}