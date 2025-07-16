#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long N, M, K;
long long res = 0;

// mod. m での a の逆元 a^{-1} を計算する
long long Modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}



long long ModComb(long long n, long long a, long long mod){
  long long i = 0;
  long long res = 1;
  while(a > 0){
    res *= ((n-i) * Modinv(a, MOD)) % MOD;
    res %= MOD;
    --a; ++i;
  }

  return res;
}


int main(){
  cin >> N >> M >> K;

  long long MC = ModComb(N * M - 2, K - 2, MOD);

  for(int d = 1; d < N; d++)
    res = ((d * ((((N-d) * M * M) * MC) % MOD)) % MOD + res) % MOD;

  for(int d = 1; d < M; d++)
    res = ((d * ((((M-d) * N * N) * MC) % MOD)) % MOD + res) % MOD;

  cout << res << endl;
  return 0;

}




    