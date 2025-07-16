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
  if (N == 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> vs;
  while (abs(N) > 0) {
    int r = abs(N) % 2;
    if (r == 1) N--;
    vs.push_back(r);
    N /= -2;
  }
  for (auto it = vs.rbegin(); it != vs.rend(); ++it) {
    cout << *it;
  }
  cout << endl;
}
