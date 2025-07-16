#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int x;
  cin >> x;
  int ans = 0;
  ans += (x / 500) * 1000;
  x %= 500;
  ans += (x / 5) * 5;

  cout << ans << endl;
}
