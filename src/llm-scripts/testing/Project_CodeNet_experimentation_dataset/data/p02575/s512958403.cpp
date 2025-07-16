#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  map<int, int> MA;
  multiset<int> MS;
  for (int i = 0; i < W; i++) MA[i] = i, MS.insert(0);
  for (int h = 1, A, B; cin >> A >> B; h++) {
    auto it = MA.lower_bound(--A);
    int tmp = -1;
    while (it != MA.end() && it -> first <= B) {
      tmp = max(tmp, it -> second);
      MS.erase(MS.find(it -> first - it -> second));
      MA.erase(it++);
    }
    if (tmp != -1 && B < W) MA[B] = tmp, MS.insert(B - tmp);
    cout << ((MS.size()) ? *MS.begin() + h : -1) << "\n";
  }
}