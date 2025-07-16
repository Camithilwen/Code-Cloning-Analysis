#include<bits/stdc++.h>

#define MOD_1_000_000_007 (1000000007LL)
#define LINF (1LL<<60)
#define rep(i, n)   for (long long i = 0; i <  (long long)(n); i++)
#define rep1(i, n)  for (long long i = 1; i <  (long long)(n); i++)
#define rep2(i, n)  for (long long i = 2; i <  (long long)(n); i++)
#define rep0c(i, n) for (long long i = 0; i <= (long long)(n); i++)
#define rep1c(i, n) for (long long i = 1; i <= (long long)(n); i++)
#define rep2c(i, n) for (long long i = 2; i <= (long long)(n); i++)
#define repc0(n, i) for (long long i = (long long)(n); i >= 0; i--)
#define repc1(n, i) for (long long i = (long long)(n); i >= 1; i--)
#define repc2(n, i) for (long long i = (long long)(n); i >= 2; i--)

namespace solver {
  using namespace std;
  typedef long long ll;

  ll M, D[200020], C[200020];

  void init() {
    scanf("%lld", &M);
    rep(i, M) scanf("%lld %lld", &D[i], &C[i]);
  }

  ll fold(ll n) {
    if (n < 10) return n;
    return (n/10)+(n%10);
  }

  void solve() {
    ll past = 0, ans = 0;
    rep(i, M) {
      ans += (C[i]-1) + (D[i]*C[i]/10);
      past *= 10;
      past += fold(D[i]*C[i]);
      while(past >= 10) {
        ans++;
        past = (past/10)+(past%10);
      }
    }
    printf("%lld\n", ans);
  }

  void solve2() {
    ll acc = 0, ans = 0;
    rep(i, M) {
      ans += C[i];
      acc += D[i]*C[i];
    }
    ans--;
    acc--;
    ans += acc/9;
    printf("%lld\n", ans);
  }
}

int main() {
  solver::init();
  solver::solve2();
  return 0;
}