#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N, K;
  cin >> N >> K;
  vl x(N);
  rep(i, N) cin >> x[i];

  ll ans = (ll)pow(10, 18);
  ll dist;

  rep(i, N - K + 1){
    if(x[i + K - 1] * x[i] < 0)
      dist = x[i + K - 1] - x[i] + min(abs(x[i + K - 1]), abs(x[i]));
    else
      dist = max(abs(x[i + K - 1]), abs(x[i]));

    ans = min(ans, dist);
  }

  cout << ans << "\n";
  
  return 0;
}
