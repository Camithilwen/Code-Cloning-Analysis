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
  int A, B; cin >> A >> B;
  vector<string> C(100);
  for (int i = 0; i < 50; ++i) {
    C[i] = string(100, '.'); // White
  }
  for (int i = 50; i < 100; ++i) {
    C[i] = string(100, '#'); // Black
  }

  --A, --B;

  for (int i = 0; i < 50 && B > 0; i += 2) {
    for (int j = 0; j < 100 && B > 0; j += 2) {
      C[i][j] = '#'; --B;
    }
  }
  for (int i = 99; i > 50 && A > 0; i -= 2) {
    for (int j = 0; j < 100 && A > 0; j += 2) {
      C[i][j] = '.'; --A;
    }
  }

  cout << 100 << " " << 100 << endl;
  for (auto s : C) cout << s << endl;
}
