#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, a[N], b[N];
int s[3 * N], p[3 * N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

  for (int i = 0; i < n; ++i) s[i] = b[i] ^ b[(i + 1) % n];
  for (int i = 0; i < n; ++i) s[i + n + 1] = a[i] ^ a[(i + 1) % n];
  for (int i = 2 * n + 1; i <= 3 * n; ++i) s[i] = s[i - n];
  s[n] = -1;

  int now = p[0] = -1;
  for (int i = 1; i <= 3 * n; ++i) {
    while (now + 1 && s[now + 1] != s[i]) now = p[now];
    p[i] = s[now + 1] == s[i] ? ++now : (now = -1);
  }

  for (int i = 2 * n; i < 3 * n; ++i) {
    if (p[i] == n - 1) {
      int k = i - 2 * n;
      int x = a[k] ^ b[0];
      printf("%d %d\n", k, x);
    }
  }
}
