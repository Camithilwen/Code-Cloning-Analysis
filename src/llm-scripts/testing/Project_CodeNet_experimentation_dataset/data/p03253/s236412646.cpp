#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAX = 2*1e5;

bool IsPrime(long long n){
  if(n == 1) return false;
  for(long long i = 2; i * i < n; i++){
    if(n%i == 0) return false;
  }
  return true;
}

vector<pair<long long, long long>> PrimeFactorize(long long n){
  vector<pair<long long, long long>> res;
  long long a = 0;
  for(long long i = 2; i * i <= n; i++){
    a = 0;
    if(n%i == 0){
      if(IsPrime(i)){
        while(n % i == 0){
          n /= i;
          a++;
        }
        res.push_back(make_pair(i, a));
    }}}
  if(n!= 1) res.push_back(make_pair(n, 1));
  return res;
}

long long modpow(long long a, long long n, long long mod){
  long long res = 1;
  while(n > 0){
    //nを２進数に分解してビットの立っているところだけ掛け算していく。
    if (n &  1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

// a inverse (mod m)
// a^(-1) = a^(p-2) (mod p)
long long modinv(long long a, long long mod){
  return modpow(a, mod-2, mod);
}

long long Comb(long long n, long long k){
  if(n < k) return 0;
  if(n < 0 || k < 0) return 0;
  // return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
  long long ans = 1;
  for(long long i = 0; i < k; i++){
    ans = ans * (n - i) % MOD;
    ans = ans * modinv(k - i, MOD) % MOD;
  }
  return ans;
}

int main(){
  long long n,m;
  cin >> n >> m;

  vector<pair<long long, long long>> res;
  res = PrimeFactorize(m);

  // CombInit();

  long long ans = 1;
  long long size = res.size();
  for(long long i = 0; i < size; i++){
    long long num = Comb(res[i].second + n - 1, res[i].second);
    // ans = (ans * Comb(res[i].second + n - 1, res[i].second)) % MOD;
    ans = (ans * num) % MOD;
  }

  cout << ans << endl;

  return 0;
}