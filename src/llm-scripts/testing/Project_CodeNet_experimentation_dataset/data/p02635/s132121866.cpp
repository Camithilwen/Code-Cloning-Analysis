#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const int mod = 998244353;
inline int add(int u, int v) {
  return u + v >= mod ? u + v - mod : u + v;
}
inline int sub(int u, int v) {
  return u >= v ? u - v : u - v + mod;
}
inline int mul(ll u, int v) {
  return u * v % mod;
}

const int N = 303, M = 1000;
int choose[M][M];

inline int partition(int n, int k) {
  return choose[n + k - 1][k - 1];
}

int ways[N][N][N]; // ways[i][j][f] = last i, j moves, f free ones

int solve(VI& ones, int k) {
  const int n = ones.size();
  if (n == 0) return 1;

  ways[n][0][0] = 1;
  for (int i = n; i >= 1; i--) {
    const int len = ones[i - 1];
    for (int j = 0; j <= k; j++) {
      for (int f = 0; f < N; f++) {
        ways[i - 1][j][f] = ways[i][j][f];
      }
    }
    for (int j = 0; j <= k; j++) {
      for (int f = N - 2; f >= 0; f--) {
        ways[i - 1][j][f] = add(ways[i - 1][j][f], ways[i - 1][j][f + 1]);
      }
    }
    for (int j = 0; j <= k; j++) {
      for (int cur = 1; cur <= len && j + cur <= k; cur++) {
        for (int f = 0; f + cur < N; f++) {
          ways[i - 1][j + cur][f + cur] = add(ways[i - 1][j + cur][f + cur], ways[i][j][f]);
        }
      }
    }
  }

  int ans = 0;
  for (int j = 0; j <= k; j++) {
    for (int f = 0; f < N; f++) {
      ans = add(ans, ways[0][j][f]);
    }
  }

  return ans;
}

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string s; cin >> s;
  int k; cin >> k;
  vector<int> ones;
  int f = 0;
  bool seen = false;
  for (char c: s) {
    if (c == '1') {
      f++;
    }
    if (c == '0') {
      if (seen) {
        ones.push_back(f);
      }
      f = 0;
      seen = true;
    }
  }
  if (f > 0 && seen) {
    ones.push_back(f);
  }

  for (int n = 0; n < M; n++) {
    choose[n][0] = choose[n][n] = 1;
    for (int r = 1; r < n; r++) {
      choose[n][r] = add(choose[n - 1][r], choose[n - 1][r - 1]);
    }
  }

  k = min(k, 300);
  cout << solve(ones, k) << endl;

  return 0;
}
