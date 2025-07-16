#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n, a, b;
  cin >> n >> a >> b;
  
  vector<ll> x(n);
  for (int i = 0; i < n; i++){
    cin >> x[i];
  }
  ll ans = 0;
  for (int i = 0; i < n-1; i++){
    ans += min(a*(x[i+1]-x[i]), b);
  }
  cout << ans << endl;

  return 0;
}
