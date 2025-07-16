#include <algorithm>
#include <cstdio>
#include <string>
#define MAXN 1000001
#define a first
#define b second

char buf[MAXN];
std::pair<int, int> s[MAXN];

int main() {
  using namespace std;

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", buf);
    s[i].a = s[i].b = 0;
    for (int j = 0; buf[j]; ++j) {
      if (buf[j] == '(')
        ++s[i].a;
      else {
        if (s[i].a)
          --s[i].a;
        else
          ++s[i].b;
      }
    }
  }

  auto cmp = [](const pair<int, int> &l, const pair<int, int> &r) {
    if (l.a <= l.b && r.a > r.b)
      return true;
    else if (l.a > l.b && r.a <= r.b)
      return false;
    else if (l.a > l.b && r.a > r.b)
      return l.b > r.b;
    else
      return l.a < r.a;
  };

  std::sort(s, s + n, cmp);

  int t = 0;
  for (int i = 0; i < n; i++) {
    if (t < s[i].a) {
      printf("No\n");
      return 0;
    }
    t += s[i].b - s[i].a;
  }
  if (t)
    printf("No\n");
  else
    printf("Yes\n");

  return 0;
}
