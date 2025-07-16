
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define inf 0x3f3f3f

#define maxn 1000005

int n, pos, ans, head, tail;
int q[maxn];
char s[maxn], t[maxn];

int main() {
  scanf("%d%s%s", &n, s + 1, t + 1);
  if (strcmp(s + 1, t + 1) == 0) {
    putchar('0');
    return 0;
  }
  pos = n;
  head = 1;
  tail = 0;
  for (int i = n; i >= 1; i--) {
    if (t[i] == t[i - 1])
      continue;
    pos = min(pos, i);
    while (pos && t[i] != s[pos])
      pos--;
    if (pos == 0) {
      putchar('-');
      putchar('1');
      return 0;
    }
    while (head <= tail) {
      if (q[head] - (tail - head + 1) + 1 > i)
        head++;
      else
        break;
    }
    q[++tail] = pos;
    if (i != pos)
      ans = max(ans, tail - head + 1);
  }
  printf("%d\n", ans + 1);
  return 0;
}
