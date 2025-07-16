#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

bool isprime(ll n){
  if (n == 0 || n == 1)
    return false;

  for (ll i = 2; i*i <= n; i++){
    if (n % i == 0)
      return false;
  }

  return true;
}

int main(void){
  ll n;
  cin >> n;
  
  ll ans = 1;
  for (ll i = 0; i <= n; i++){
    if (isprime(i)){
      ll t = 1;
      ll j = i;
      while (j <= n){
        t += n / j;
        j *= i;
      }

      ans = ans * t % MOD;
    }
  }
  cout << ans << endl;

  return 0;
}
