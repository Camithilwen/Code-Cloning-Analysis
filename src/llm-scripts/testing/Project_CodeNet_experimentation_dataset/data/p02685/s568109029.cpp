#include <bits/stdc++.h>
#include <fstream>
using namespace std;

const int MAX = 510000;
const int MOD = 998244353;
long long fac[MAX], finv[MAX], inv[MAX];


void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  long long N, M, K;
  cin >> N >> M >> K;
  vector<long long> vec(N+1);// i個のブロックの塊をM色で隣合う色が異なるように塗る数
  vec[0] = 0;
  vec[1] = M;
  COMinit();
  for(int i = 2; i <= N; i++){
    vec[i] = vec[i-1] * (M-1) % MOD;
    vec[i] %= MOD;
  }
  long long sum = 0;
  for(int i = 0; i <= K; i++){
    sum += COM(N-1, i) * vec[N - i] % MOD;
    sum %= MOD;
  }
  cout << sum <<endl;
}
