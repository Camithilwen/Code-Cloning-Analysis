#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n-1; i >= 0; i--)
using namespace std;

int main(){
  ll n, m;
  cin >> n >> m;
  ll mx = m / n;
  ll ans;
  repr(i, mx+1){
    if (m % i == 0){
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  
  return 0;
}