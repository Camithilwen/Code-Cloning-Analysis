#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
LL pw[87];

LL dfs(int i, LL d, int fg) {
   if (i == 0) return d == 0 ? 1 : 0;
   if (i == 1) return d == 0 ? 10 : 0;
   LL D = (10 - (d % 10)) % 10;
   //printf("i = %d d = %lld D = %lld\n", i, d, D);
   LL c = 9 - D + 1 - fg;
   d = d - pw[i - 1] * D + D;
   return c * dfs(i - 2, abs(d) / 10, 0);
}

int main() {
    LL D;
    while (~scanf("%lld", &D)) {
          LL ans = 0;
          pw[0] = 1;
          for (int i = 1; i <= 18; i++) {
              pw[i] = pw[i - 1] * 10;
          }
          for (int i = 1; i <= 18; i++) {
              ans += dfs(i, D, 1);
          }
          printf("%lld\n", ans);
    }
    return 0;
}
