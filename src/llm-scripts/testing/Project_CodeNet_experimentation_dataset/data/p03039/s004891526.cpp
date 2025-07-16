#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long modpow(long long a, long long b){
  long long ans = 1;
  while (b > 0){
    if (b % 2 == 1){
      ans *= a;
      ans %= MOD;
    }
    a *= a;
    a %= MOD;
    b /= 2;
  }
  return ans;
}
long long modinv(long long a){
  return modpow(a, MOD - 2);
}
vector<long long> mf = {1};
long long modfact(int n){
  if (mf.size() > n){
    return mf[n];
  } else {
    for (int i = mf.size(); i <= n; i++){
      long long next = mf.back() * i % MOD;
      mf.push_back(next);
    }
    return mf[n];
  }
}
long long modbinom(int n, int k){
  return modfact(n) * modinv(modfact(k)) % MOD * modinv(modfact(n - k)) % MOD;
}
int main(){
  long long N, M, K;
  cin >> N >> M >> K;
  long long ans1 = 0;
  for (int i = 1; i <= N; i++){
    ans1 += (N - i) * i;
  }
  ans1 %= MOD;
  ans1 *= M;
  ans1 %= MOD;
  ans1 *= M;
  ans1 %= MOD;
  long long ans2 = 0;
  for (int i = 1; i <= M; i++){
    ans2 += (M - i) * i;
  }
  ans2 %= MOD;
  ans2 *= N;
  ans2 %= MOD;
  ans2 *= N;
  ans2 %= MOD;
  long long ans = ans1 + ans2;
  ans %= MOD;
  ans *= modbinom(N * M - 2, K - 2);
  ans %= MOD;
  cout << ans << endl;
}