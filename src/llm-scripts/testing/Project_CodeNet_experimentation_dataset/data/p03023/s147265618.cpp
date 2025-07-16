#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 200010;
int n, ans;

int read()
{
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * w;
}

inline void write(int x)
{
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[-- top] + 48);
}

signed main()
{
    n = read();
    ans = (n - 2) * 180;
    write(ans);
    return 0;
}