#include <bits/stdc++.h>
using namespace std;

const int N = 303;
const int MOD = 998244353;

int n, k;
char s[N];

vector<int> ones;

int dp[N][N][N];
int f(int x, int use, int sum) {
  if (use > k) return 0;
  if (x < 0) return sum == 0;
  if (~dp[x][use][sum]) return dp[x][use][sum];

  int ret = f(x-1, use, sum);
  for (int i = 1; i <= ones[x]; ++i) {
    ret = (ret + f(x-1, use + i, sum + i)) % MOD;
  }
  for (int i = 1; i <= sum; ++i) {
    ret = (ret + f(x-1, use, sum - i)) % MOD;
  }

  return dp[x][use][sum] = ret;
}

int solve() {
  scanf("%s %d", s, &k);
  
  int n = strlen(s);
  ones.push_back(0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      ones.push_back(0);
    } else {
      ++ones.back();
    }
  }

  // for (int o: ones) cerr << o << " "; cerr << endl;

  memset(dp, -1, sizeof dp);
  printf("%d\n", f((int) ones.size() - 1, 0, 0));
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}
