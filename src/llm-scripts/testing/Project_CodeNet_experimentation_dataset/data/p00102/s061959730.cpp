#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n = 0, tmp0 = 0, tmp1 = 0;
  int tmp2 = 0, tmp3, out1 = 0, out2 = 0;
  int a[100];
  scanf("%d", &n);
  while (n) {
    for (tmp3=0;tmp3<100;tmp3++) a[tmp3] = 0;
    tmp0 = 0, out2 = 0;
    while (tmp0 < n) {
      tmp1 = 0, out1 = 0;
      while (tmp1 < n) {
        scanf("%d", &tmp2);
        a[tmp1] += tmp2;
        printf("%5d", tmp2);
        out1 += tmp2;
        tmp1++;
      }
      printf("%5d\n", out1);
      a[tmp1] += out1;
      tmp0++;
    }
    tmp0 = 0;
    while (tmp0 < n) {
      printf("%5d", a[tmp0]);
      tmp0++;
    }
    printf("%5d\n", a[tmp0]);
    scanf("%d", &n);
  }
  return 0;
}