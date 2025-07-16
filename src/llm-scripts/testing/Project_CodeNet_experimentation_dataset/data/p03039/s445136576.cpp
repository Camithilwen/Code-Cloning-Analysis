#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAX_FACT = 1e5 * 2 + 1;

ll fact[MAX_FACT], invFact[MAX_FACT], inv[MAX_FACT];

void init() {
  fact[0] = fact[1] = 1;
  invFact[0] = invFact[1] = 1;
  inv[1] = 1;
  for (auto i = 2; i < MAX_FACT; ++i)
  {
    fact[i] = fact[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    invFact[i] = invFact[i - 1] * inv[i] % MOD;
  }
}

ll calcCombination(ll n, ll k) {
  if (n < k) {
    return 0;
  }
  if (n < 0 || k < 0) {
    return 0;
  }
  return fact[n] * (invFact[k] * invFact[n - k] % MOD) % MOD;
}

int main()
{
  ll N, M, K;
  cin >> N >> M >> K;

  init();

  ll result = 0;
  for (int i = 1; i < N; i++) {
    result = (result + i * (N - i) * M % MOD * M % MOD) % MOD;
  }
  for (int i = 1; i < M; i++) {
    result = (result + i * (M - i) * N % MOD * N % MOD) % MOD;
  }
  result = result * calcCombination(N * M - 2, K - 2) % MOD;
  cout << result << endl;
  return 0;
}