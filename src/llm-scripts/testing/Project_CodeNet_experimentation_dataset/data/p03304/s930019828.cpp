#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
#include <vector>

int main() {
  int n, m, d;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &d);
  long long denominator;
  if (d!=0) {
    denominator = (2*(double)n-2*(double)d)*(m-1);
  } else {
    denominator = (double)n*(m-1);
  }
  double ans = denominator/pow(n, 2);
  printf("%.10lf\n", ans);
  return 0;
}
