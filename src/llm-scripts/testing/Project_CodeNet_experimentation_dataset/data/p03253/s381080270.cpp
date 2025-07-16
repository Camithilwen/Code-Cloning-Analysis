#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000010;
const int64_t MOD = 1000000007;
int64_t fac[MAX], finv[MAX], inv[MAX];

void COMinit()
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

int64_t COM(int64_t n, int64_t k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

vector<pair<int64_t, int64_t>> prime_factorize(int64_t N)
{
  vector<pair<int64_t, int64_t>> res;
  for (int64_t a = 2; a * a <= N; a++)
  {
    if (N % a != 0)
      continue;
    int64_t ex = 0;
    while (N % a == 0)
    {
      ex++;
      N /= a;
    }
    res.push_back({a, ex});
  }
  if (N != 1)
    res.push_back({N, 1});
  return res;
}

int64_t nHk(int64_t n, int64_t k)
{
  if (k == 1)
  {
    return n;
  }
  return COM(n + k - 1, k);
}

int main()
{
  int64_t N, M, ans = 1;
  cin >> N >> M;
  const auto &res = prime_factorize(M);
  COMinit();
  for (auto p : res)
  {
    (ans *= nHk(N, p.second)) %= MOD;
  }
  cout << ans << endl;
}