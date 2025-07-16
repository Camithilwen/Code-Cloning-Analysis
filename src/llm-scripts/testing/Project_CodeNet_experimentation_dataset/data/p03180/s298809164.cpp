#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9+7;
int main() {
  // U: 3^N fits, which hints towards a fancy subset DP
  // i.e. the one that is magically 3^n when it looks like
  // it should be 2^2n

  cin.tie(0);
  cin.sync_with_stdio(0);
  int n; cin >> n;

  long long a[n][n];
  for(int i = 0; i<n; ++i) {
    for(int j = 0; j<n; ++j) {
      cin >> a[i][j];
    }
  }

  // first, compute the costs of every subset (if grouped)
  long long costs[1<<n];
  for(int i = 0; i<(1<<n); ++i) {
    vector<int> in_group;
    for(int j = 0; j<n; ++j) {
      if((i >> j) & 1) {
        in_group.push_back(j);
      }
    }
    costs[i] = 0;
    for(int j = 0; j<in_group.size(); ++j) {
      for(int k = j+1; k<in_group.size(); ++k) {
        costs[i] += a[in_group[j]][in_group[k]];
      }
    }
  }

  // next, magic
  long long dp[1<<n];
  for(int i = 0; i<(1<<n); ++i) {
    dp[i] = LLONG_MIN;
  }
  dp[0] = 0;
  for(int i = 0; i<(1<<n); ++i) {
    // ugh I can't quite remember it...
    int j = i;
    do {
      j = (j - 1) & i; // go through all masks containing i as a submask...
      dp[i] = max(dp[i], dp[j] + costs[i^j]);
    } while (j != i);
  }

  cout << dp[(1<<n)-1] << endl;
}
