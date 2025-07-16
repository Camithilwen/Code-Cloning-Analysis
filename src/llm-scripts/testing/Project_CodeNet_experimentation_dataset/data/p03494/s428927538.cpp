#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
ll div_2(ll a) {
  ll ans = 0;
  while(a % 2 == 0) {
    ans++;
    a /= 2;
  }
  return ans;
}
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  ll min = 1000000000;
  rep(i, N) {
    cin >> A[i];
    if(min > div_2(A[i])) {
      min = div_2(A[i]);
    }
  }
  cout << min << endl;
}
