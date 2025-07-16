#include<bits/stdc++.h>

using namespace std;

const int N = 123456;

int n, m, color[N];
vector<int> adj[N];
bool visit[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int a = 0, b = 0, c = 0, number;
  bool ok;
  for (int i = 1; i <= n; ++i) {
    if (!visit[i]) {
      function<void (int, int)> dfs = [&] (int x, int z) {
        ++number;
        visit[x] = true;
        color[x] = z;
        for (auto y : adj[x]) {
          if (!visit[y]) {
            dfs(y, !z);
          } else if (color[y] != (!z)) {
            ok = false;
          }
        }
      };
      number = 0;
      ok = true;
      dfs(i, 0);
      if (number == 1) {
        ++a;
      } else if (!ok) {
        ++b;
      } else {
        ++c;
      }
    }
  }
  long long answer = 0;
  answer += (long long) a * a;
  answer += (long long) a * (n - a) << 1;
  answer += (long long) b * b;
  answer += (long long) b * c << 1;
  answer += (long long) c * c << 1;
  cout << answer << '\n';
  return 0;
}