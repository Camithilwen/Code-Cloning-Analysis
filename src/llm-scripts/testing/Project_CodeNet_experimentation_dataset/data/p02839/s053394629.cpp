#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <unordered_set>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;

using namespace std;

const int B = 12750;
bitset<B> dp[81][81];
int vs[81][81];

int main(void) {
  int h, w;
  scanf("%d%d", &h, &w);
  REP(i, h) {
    REP(j, w) {
      scanf("%d", &vs[i][j]);
    }
  }
  REP(i, h) {
    REP(j, w) {
      int v;
      scanf("%d", &v);
      vs[i][j] = abs(vs[i][j]-v);
    }
  }
  // cerr << "> " << vs[0][0] << endl;
  dp[0][0].set(vs[0][0]);
  REP(i, h) {
    REP(j, w) {
      if(i == 0 && j == 0) {
        continue;
      }
      int v = vs[i][j];
      auto &s = dp[i][j];
      bitset<B> b;
      if(i-1 >= 0) {
        b = dp[i-1][j];
      }
      if(j-1 >= 0) {
        b |= dp[i][j-1];
      }
      s = b << v;
      s |= b >> v;
      REP(x, v) {
        if(b[x]) {
          s.set(v - x);
        }
      }
      // cerr << s << endl;
    }
  }
  const auto &s = dp[h-1][w-1];
  REP(i, B) {
    if(s[i]) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
