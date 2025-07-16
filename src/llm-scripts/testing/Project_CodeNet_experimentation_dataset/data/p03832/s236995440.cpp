#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

////////////////////////////////
#define P 1000000007
#define N_MAX 2000000
typedef long long int ll;
ll fac[N_MAX+1];
ll inv[N_MAX+1];
ll finv[N_MAX+1];

ll comb(ll n, ll k){
    return (((fac[n]*finv[n-k])%P)*finv[k])%P;
}

void init(){
    fac[0] = finv[0] = fac[1] = finv[1] = inv[1] = 1;
    for(int i = 2; i <= N_MAX; i++){
        fac[i] = (fac[i-1]*i)%P;
        inv[i] = ((-(P/i)*inv[P%i])%P+P)%P;
        finv[i] = (finv[i-1]*inv[i])%P;
    }
}
ll pp(ll a, ll b){
  return (a * b)%P;
}
ll pd(ll a, ll b){
  return (a * inv[b])%P;
}
//////////////////////////////////////
int main(int argc, char const *argv[]) {
  ll N, A, B, C, D;
  init();
  std::cin >> N >> A >> B >> C >> D;
  vvl dp = vv(B+1, N+1, 0, ll);
  dp[A-1][0] = 1;
  for(int i=A;i<=B;i++){
    ll tmp = 1;
    for(int j=0;j<N+1;j++) dp[i][j] = dp[i-1][j];
    for(int j=0;j<C;j++) tmp = pp(tmp, finv[i]);
    for(int j=C;j<=D;j++, tmp = pp(tmp, finv[i])){
      for(int k=0;k+i*j<N+1;k++){
        dp[i][i*j+k] = (dp[i][i*j+k] + pp(pp(dp[i-1][k], pp(pp(fac[N-k], tmp), finv[N-k-i*j])), finv[j]))%P;
      }
    }
  }
  /*
  for(int i=1;i<=B;i++){
    for(int j=0;j<=N;j++) std::cout << dp[i][j] << " ";
    std::cout << '\n';
  }
  */
  std::cout << dp[B][N] << '\n';
  return 0;
}
