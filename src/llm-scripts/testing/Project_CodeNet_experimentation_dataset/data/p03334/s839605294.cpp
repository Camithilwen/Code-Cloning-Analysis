%:pragma GCC optimize("Ofast")
  %:pragma GCC optimize("inline")
#include <bits/stdc++.h>
#define rint register int
#define fo(i, n) for(rint i = 1; i <= (n); i ++)
#define out(x) cerr << #x << " = " << x << "\n"
#define type(x) __typeof((x).begin())
#define foreach(it, x) for(type(x) it = (x).begin(); it != (x).end(); ++ it)
  using namespace std;
// by piano
template<typename tp> inline void read(tp &x) {
  x = 0;char c = getchar(); bool f = 0;
  for(; c < '0' || c > '9'; f |= (c == '-'), c = getchar());
  for(; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
  if(f) x = -x;
}
#define P pair<int, int>
#define fi first
#define se second
const int N = 633;
vector<P> vec;
int n, d1, d2;
int col1[N][N], col2[N][N], col[N][N];
inline void dfs(int x, int y, int fff) {
  if(col[x][y] != -1) return ;
  col[x][y] = fff;
  for(auto v: vec) {
    int dx = x + v.first;
    int dy = y + v.second;
    if(dx < 0 || dx >= 2 * n || dy < 0 || dy >= 2 * n)
       continue;
    dfs(dx, dy, fff ^ 1);
  }
}               

inline void cal(int d) {
  vec.clear();
  for(int dx = -2 * n + 1; dx < 2 * n; dx ++) {
    for(int dy = -2 * n + 1; dy < 2 * n; dy ++) {
      if(dx * dx + dy * dy == d)
        vec.push_back(P(dx, dy));
    }
  }
  memset(col, -1, sizeof col);
  for(int x = 0; x < 2 * n; x ++)
    for(int y = 0; y < 2 * n; y ++)
      dfs(x, y, 0);
}
main(void) {
  read(n); read(d1); read(d2);
  cal(d1); memcpy(col1, col, sizeof col);
  cal(d2); memcpy(col2, col, sizeof col);
  for(int k1 = 0; k1 < 2; k1 ++) {
    for(int k2 = 0; k2 < 2; k2 ++) {
      int cnt = 0;
      for(int x = 0; x < 2 * n; x ++) {
        for(int y = 0; y < 2 * n; y ++)
          if(col1[x][y] == k1 && col2[x][y] == k2)
            ++ cnt;
      }
      if(cnt >= n * n) {
        int res = n * n;
        for(int x = 0; x < 2 * n; x ++) 
          for(int y = 0; y < 2 * n; y ++)
            if(col1[x][y] == k1 && col2[x][y] == k2) {
              -- res;
              cout << x << " " << y << "\n";
              if(res == 0) return 0;
            }
      }
    }
  }
}
