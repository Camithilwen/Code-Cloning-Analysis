#include <bits/stdc++.h>
using namespace std;

int64_t modpow(int64_t x, int64_t n) {
    const int MOD = 998244353;
    x = x%MOD;
    if(n==0) return 1;  //再帰の終了条件

    else if(n%2==1) {
        return (x*modpow(x, n-1))%MOD;  //nが奇数ならnを1ずらす
    }
    else return modpow((x*x)%MOD, n/2)%MOD;  //nが偶数ならnが半分になる
}

int main() {
  int64_t n,m,k;
  cin>>n>>m>>k;
  const int MOD = 998244353;

  int64_t m_1[k+1];
  int64_t start = n-1-k;
  m_1[0] = modpow(m-1, start);
  for(int i=1; i<=k; i++) {
    m_1[i] = (m_1[i-1]*(m-1))%MOD;
  }

  int64_t ans = 0;
  int64_t comb = 1;
  for(int i=0; i<=k; i++) {
    int64_t add = (comb*m_1[k-i])%MOD;
    ans += add;
    ans = ans%MOD;
    comb = (comb*(n-1-i))%MOD;
    int64_t div = modpow((i+1), MOD-2);
    comb = (comb*div)%MOD;
  }

  ans = (ans*m)%MOD;

  cout<<ans<<endl;


  return 0;
}