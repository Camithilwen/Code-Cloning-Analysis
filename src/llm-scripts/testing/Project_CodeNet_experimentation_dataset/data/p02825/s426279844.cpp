// Written by newbiechd
#include <cstring>
#include <iostream>
#include <string>

const int maxN = 13;
int n;
char col[maxN][maxN];
bool vis[26];
void dfs(int x, int y, char c) {
  if (x > n) {
    int val = 0;
    memset(vis, 0, sizeof(vis));
    for (int j = 1; j <= n; ++j) vis[col[1][j] - 'a'] = 1;
    for (char t = 'a'; t <= c; ++t) val += vis[t - 'a'];
    if (val != 3)
      return ;
    for (int i = 2; i <= n; ++i) {
      memset(vis, 0, sizeof(vis));
      int tmp = 0;
      for (int j = 1; j <= n; ++j) vis[col[i][j] - 'a'] = 1;
      for (char t = 'a'; t <= c; ++t) tmp += vis[t - 'a'];
      if (tmp != val)
        return ;
    }
    for (int j = 1; j <= n; ++j) {
      memset(vis, 0, sizeof(vis));
      int tmp = 0;
      for (int i = 1; i <= n; ++i) vis[col[i][j] - 'a'] = 1;
      for (char t = 'a'; t <= c; ++t) tmp += vis[t - 'a'];
      if (tmp != val)
        return ;
    }
    for (int i = 1; i <= n; ++i)
      printf("%s\n", col[i] + 1);
    putchar('\n'), fflush(stdout);
    return ;
  }
  if (y > n) {
    dfs(x + 1, 1, c);
    return ;
  }
  if (col[x][y - 1] == '.') {
    col[x][y] = col[x][y - 1] = c;
    dfs(x, y + 1, c + 1);
    col[x][y] = col[x][y - 1] = '.';
  }
  if (col[x - 1][y] == '.') {
    col[x][y] = col[x - 1][y] = c;
    dfs(x, y + 1, c + 1);
    col[x][y] = col[x - 1][y] = '.';
  }
  dfs(x, y + 1, c);
}

const std::string ans[][7] = {
  {
    "aabc",
    "ddbc",
    "efgg",
    "efhh"
  },
  {
    "aabbd",
    "ccf.d",
    "eefgg",
    "..hij",
    "..hij"
  },
  {
    "aabbcc",
    "ddeeff",
    "ghi...",
    "ghi...",
    "...jkl",
    "...jkl"
  },
  {
    "aabbcc.",
    "ddee..h",
    "ffgg..h",
    "....ijk",
    "....ijk",
    "....lmn",
    "....lmn"
  }
};

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  /*
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      col[i][j] = '.';
  dfs(1, 1, 'a');
  */
  
  if (n < 3) {
    printf("-1\n");
    return 0;
  }
  if (n == 3) {
    std::cout << "aa.\n..a\n..a\n";
    return 0;
  }

  int k = (n & 3) + 4;
  for (int i = 0; i < n - k; ++i) {
    std::string str(n, '.');
    str.replace(i / 4 * 4, 4, ans[0][i % 4]);
    std::cout << str << '\n';
  }
  for (int i = n - k; i < n; ++i) {
    std::string str(n, '.');
    str.replace(n - k, k, ans[k - 4][i + k - n]);
    std::cout << str << '\n';
  }
  return 0;
}
