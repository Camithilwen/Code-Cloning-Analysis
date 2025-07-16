#pragma GCC optimize(2)
#pragma GCC optimize("inline")
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define mp make_pair
#define pb push_back
using namespace std;

typedef long long li;
template<class T>inline void read(T &x) {
  x = 0;
  T tmp = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') tmp = -1, c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + c - '0', c = getchar();
  x *= tmp;
}
template<class T>inline void Max(T &x, T y) {
  if (y > x) x = y;
}
template<class T>inline void Min(T &x, T y) {
  if (y < x) x = y;
}

const int N = 600;
int n, d1, d2, a[N][N], b[N][N];

const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1};
inline bool out(int x, int y) {
  return x < 0 || y < 0 || x >= (n << 1) || y >= (n << 1);
}

vector<pair<int, int> > g, h;

struct node {
  int x, y, ty;
  node() {}
  node(int _x, int _y, int _ty) : x(_x), y(_y), ty(_ty) {}
};
queue<node> q;
void Fill_a(int Ax, int Ay) {
  q.push(node(Ax, Ay, 0));
  while (!q.empty()) {
    int x = q.front().x, y = q.front().y;
    int cur = q.front().ty;
    q.pop();
    if (a[x][y] != -1) continue;
    a[x][y] = cur;
    for (int i = 0; i < (int)g.size(); ++i) {
      int nowx = x + g[i].first, nowy = y + g[i].second;
      if (out(nowx, nowy) || a[nowx][nowy] != -1) continue;
      q.push(node(nowx, nowy, cur ^ 1));
    }
  }
}
void Fill_b(int Ax, int Ay) {
  q.push(node(Ax, Ay, 0));
  while (!q.empty()) {
    int x = q.front().x, y = q.front().y;
    int cur = q.front().ty;
    q.pop();
    if (b[x][y] != -1) continue;
    b[x][y] = cur;
    for (int i = 0; i < (int)h.size(); ++i) {
      int nowx = x + h[i].first, nowy = y + h[i].second;
      if (out(nowx, nowy) || b[nowx][nowy] != -1) continue;
      q.push(node(nowx, nowy, cur ^ 1));
    }
  }
}

int main(void) {
  read(n), read(d1), read(d2);
  for (int i = 0; i < 450; ++i)
    for (int j = 0; j < 450; ++j) {
      int now = i * i + j * j;
      if (now == d1) {
	for (int t = 0; t < 4; ++t)
	  g.pb(mp(i * dx[t], j * dy[t]));
      }
      if (now == d2) {
	for (int t = 0; t < 4; ++t)
	  h.pb(mp(i * dx[t], j * dy[t]));
      }
    }
  for (int i = 0; i < (n << 1); ++i)
    for (int j = 0; j < (n << 1); ++j)
      a[i][j] = b[i][j] = -1;
  for (int i = 0; i < (n << 1); ++i)
    for (int j = 0; j < (n << 1); ++j)
      if (a[i][j] == -1) Fill_a(i, j);
  for (int i = 0; i < (n << 1); ++i)
    for (int j = 0; j < (n << 1); ++j)
      if (b[i][j] == -1) Fill_b(i, j);
  
  for (int x = 0; x < 2; ++x)
    for (int y = 0; y < 2; ++y) {
      int cnt = 0;
      for (int i = 0; i < (n << 1); ++i)
	for (int j = 0; j < (n << 1); ++j)
	  cnt += (a[i][j] == x && b[i][j] == y);
      if (cnt >= n * n) {
	int m = n * n;
	for (int i = 0; i < (n << 1) && m; ++i)
	  for (int j = 0; j < (n << 1) && m; ++j)
	    if (a[i][j] == x && b[i][j] == y)
	      printf("%d %d\n", i, j), --m;
	return 0;
      }
    }
}
