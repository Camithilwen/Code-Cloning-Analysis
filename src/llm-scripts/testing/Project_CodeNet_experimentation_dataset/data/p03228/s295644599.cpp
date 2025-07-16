#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  int tk = a, ao = b;
  for (int i = 0; i < k; ++i) {
    if (i % 2 == 0) {
      if (tk & 1) {
        tk--;
      }
      ao += tk / 2;
      tk /= 2;
    } else {
      if (ao & 1) {
        ao--;
      }
      tk += ao / 2;
      ao /= 2;
    }
  }
  cout << tk << " " << ao << endl;
  return 0;
}