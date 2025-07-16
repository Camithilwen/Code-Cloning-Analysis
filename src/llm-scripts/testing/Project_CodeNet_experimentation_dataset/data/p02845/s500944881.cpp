#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  int N; cin >> N;
  vector<int> c(N + 1, 0);
  c[0] = 3;

  LL v = 1;
  int index = 0;
  for (int i = 0; i < N; ++i) {
    int x; cin >> x;
    LL y = c[x];
    v = (v * y) % kMod;

    --c[x];
    ++c[x+1];

#if 0
    index = max(index, x + 1);
    cout << x << ":";
    for (int i = 0; i <=index; ++i) cout << c[i] << " ";
    cout << "->" << y << endl;
#endif
  }
  cout << v << endl;
}
