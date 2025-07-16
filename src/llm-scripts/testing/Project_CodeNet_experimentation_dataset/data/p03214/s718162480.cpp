#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int s = accumulate(a.begin(), a.end(), 0);
  int best = 1 << 30;
  int bestI = -1;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    int cur = abs(x * n - s);
    if (cur < best) {
      best = cur;
      bestI = i;
    }
  }
  cout << bestI << endl;
  return 0;
}
