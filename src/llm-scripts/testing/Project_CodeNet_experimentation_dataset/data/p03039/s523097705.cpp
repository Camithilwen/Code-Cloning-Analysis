#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll Pow(ll A, ll N){
  if (N ==0) return 1;
  else if (N % 2 == 0) return Pow(A*A%MOD, N/2);
  else return Pow(A*A%MOD, N/2) * A % MOD;
}


int main(){
  ll N, M, K; cin >> N >> M >> K;

  ll cnt1 = 0, cnt2 = 0;
  for (ll i = 0; i <= N - 1; i++){
    cnt1 += i * (N - i); cnt1 %= MOD;
  }
  cnt1 *= M * M % MOD; cnt1 %= MOD;
  for (ll i = 0; i <= M - 1; i++){
    cnt2 += i * (M - i); cnt2 %= MOD;
  }
  cnt2 *= N * N % MOD; cnt2 %= MOD;
  ll ans = (cnt1 + cnt2) % MOD;

  ll nCr = 1;
  for (ll i = 1; i <= K - 2; i++){
    nCr *= N * M - 1 - i; nCr %= MOD;
    nCr *= Pow(i, MOD-2); nCr %= MOD;
  }
  ans *= nCr; ans %= MOD;
  cout << ans << endl;


  return 0;
}
