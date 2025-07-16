#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  map<int, int> m;
  multiset<int> s;
  for (int w = 1; w <= W; ++w) {
    m[w] = w;
    s.insert(0);
  }

  int a, b;
  for (int h = 1; h <= H; ++h) {
    cin >> a >> b;
    auto it = m.lower_bound(a);
    int mx = -1;
    while (it != m.end() && it->first <= b + 1) {
      mx = max(mx, it->second);
      int d = it->first - it->second;
      s.erase(s.find(d));
      m.erase(it++);
    }

    if (mx != -1 && b + 1 <= W) {
      s.insert(b+1 - mx);
      m[b+1] = mx;
    }
    if (s.empty()) {
      cout << -1 << '\n';
    } else {
      cout << *s.begin() + h << '\n';
    }
  }
  return 0;
}

