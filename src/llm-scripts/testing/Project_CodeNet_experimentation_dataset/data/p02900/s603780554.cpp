#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

set<ll> primeFactorization( ll n ){
  set<ll> a = {1};
  while( n != 1 ){
    ll root = (ll)sqrt(n);
    for(ll i=2;i<=n;++i){
	  if( i > root ){
        a.insert(n);
        n /= n;
        break;
      }
      if( n%i == 0 ){
        a.insert(i);
        n /= i;
        break;
      }
    }
  }
  return a;
}


int main() {
  ll a,b;cin >> a >> b;
  ll num = __gcd(a,b);
  set<ll> array = primeFactorization(num);

  //for( auto p : array ) cout << p << endl;
  cout << array.size() << endl;
  return 0;
}