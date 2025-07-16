#include <bits/stdc++.h>
using namespace std;

int n, m, a[333];

int main(void) {
  scanf("%d%d", &n, &m);
  if(m == 1) {
    if(n == 1) {
      printf("1\n1\n1\n");
    } else {
      printf("%d\n2\n1 %d\n", n, n - 1);
    }
    return 0;
  }
  int cnt = 0;
  for(int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
    cnt += a[i] & 1;
  }
  if(cnt > 2) {
    return puts("Impossible"), 0;
  }
  for(int i = 2; i <= m; i++) {
    if(a[i] & 1) {
      if(~a[1] & 1) {
	swap(a[1], a[i]);
      } else {
	swap(a[m], a[i]);
      }
    }
  }
  for(int i = 1; i <= m; i++) {
    printf("%d%c", a[i], i == m ? '\n' : ' ');
  }
  int i = 1;
  if(a[1] == 1) {
    i++;
  }
  printf("%d\n", m - i + 1);
  for(; i < m; i++) {
    printf("%d ", i == 1 ? a[i] - 1 : a[i]);
  }
  printf("%d\n", a[m] + 1);
  return 0;
}
