#include <bits/stdc++.h>

using namespace std;
const long long MOD=998244353;
long long fact[200009], inv_fact[200009];

long long modpow(long long a, long long n, long long mod){
  long long ret = 1;
  while(n>0){
    if(n&1)ret = ret * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ret;
}

long long modinv(long long a, long long mod){
  return modpow(a, mod-2, mod);
}

long long nCr(long long n, long long r, long long mod){
  return (((fact[n]*inv_fact[n-r])%MOD)*inv_fact[r])%MOD;
}

int main(){
  long long n, m, k;
  cin >>n >> m >> k;
  long long cnt=0;
  
  fact[0]=1;inv_fact[0]=1;
  for(int i=1;i<=n;i++){
    fact[i]=(fact[i-1]*i)%MOD;
    inv_fact[i] = modinv(fact[i], MOD);
  }
  for(int i=0;i<=k;i++){
    long long lcnt=m;
    lcnt = (lcnt * nCr(n-1, i, MOD))%MOD;
    lcnt = (lcnt * modpow(m-1, n-1-i, MOD))%MOD;
    cnt = (cnt + lcnt)%MOD;
  }
  cout << cnt << endl;
}

