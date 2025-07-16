#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll P = 998244353;
ll f(ll b, ll n) {if (n <= 0) return 1; auto p = f(b, n / 2); return p * p % P * (n % 2 ? b : 1) % P;}
ll ms[200001];
int main()
  {int N, M, K, ans = 0; cin >> N >> M >> K;
  ms[0] = 1; for (int r = 1; r <= K; ++r) ms[r] = ms[r - 1] * (N - 1 - r + 1) % P * f(r, P - 2) % P;
  for (int k = 0; k <= K; ++k) ans = (ans + ms[k] * M % P * f(M - 1, N - k - 1) % P) % P;
  cout << ans << endl;}