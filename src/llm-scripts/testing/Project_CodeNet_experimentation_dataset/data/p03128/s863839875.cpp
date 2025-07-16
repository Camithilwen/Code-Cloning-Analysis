#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int m;
vector<int> v;
int num[10] = {0,2,5,5,4,5,6,3,7,6};
int dp[10010][10];
int pre[10010][10];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  for (int i = 0; i < 10010; i++) {
    for (int j = 0; j < 10; j++) {
      dp[i][j] = -1;
      pre[i][j] = -1;
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++) {
    dp[0][i] = 0;
  }
  int mx = -1;
  int pos = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = j; k < m; k++) {
        int use = num[v[j]];
        if (dp[i+use][k] < dp[i][j]+1) {
          dp[i+use][k] = dp[i][j]+1;
          pre[i+use][k] = j;
        }
        else if (dp[i+use][k] == dp[i][j]+1) {
          pre[i+use][k] = max(pre[i+use][k],j);
        }
        if (dp[i+use][k] > mx && i+use == n) {
          mx = dp[i+use][k];
          pos = k;
        }
        else if (i+use == n && dp[i+use][k] == mx) {
          pos = max(pos,k);
        }
      }
    }
  }
  int y = n;
  int x = pos;
  // for (int i = 0; i <= n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout << pre[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  while (1) {
    // cout << x << " " << y << endl;
    cout << v[pre[y][x]];
    int kk = v[pre[y][x]];
    x = pre[y][x];
    y -= num[kk];
    if (y == 0) break;
  }
  cout << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/
