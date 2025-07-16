#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  ll N; cin >> N;
  ll x[N]; rep(i,N) cin >> x[i];
  ll M, K; cin >> M >> K;
  ll a[M]; rep(i,M) { cin >> a[i]; a[i]--; }
  ll diff[N-1]; rep(i,N-1) diff[i] = x[i+1] - x[i];

  ll pos[N-1]; rep(i,N-1) pos[i] = i;
  ll p_bit[N-1]; rep(i,N-1) p_bit[i] = i;
  for (int i=0; (1ull<<i)<=K; i++) {
    if (i==0) rep(i,M) swap(p_bit[a[i]-1], p_bit[a[i]]);
    else {
      ll p_tmp[N-1]; rep(i,N-1) p_tmp[i] = p_bit[i];
      rep(i,N-1) p_bit[i] = p_tmp[p_tmp[i]];
    }
    if (K&(1ull<<i)) rep(i,N-1) pos[i] = p_bit[pos[i]];
    // cout << i << ":"; rep(i,N-1) cout << p_bit[i] << " "; cout << endl;
    // rep(i,N-1) cout << pos[i] << " "; cout << endl;
  }
  ll result[M]; result[0] = x[0];
  rep(i,N-1) result[i+1] = result[i] + diff[pos[i]];
  rep(i,N) cout << result[i] << endl;
  return 0;
}