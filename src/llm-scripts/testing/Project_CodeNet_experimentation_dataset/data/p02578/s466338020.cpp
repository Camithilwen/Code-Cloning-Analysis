#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N;
  cin >> N;
  vector<ll> A(N, 0);
  rep(i, N) cin >> A[i];
  ll high = A[0], ans = 0;
  rep(i, N){
    ans += max(high - A[i], 0LL);
    chmax(high, A[i]);
  }
  cout << ans << endl;
}
