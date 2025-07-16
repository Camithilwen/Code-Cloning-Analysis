#include <bitset>
#include <cmath>
#include <iostream>

using namespace std;

int a(int i) {
  int ret{};
  for (int j = 0; j != i; ++j) {
    ret += lround(pow(2, 2 * j + 1));
  }
  return ret;
}

int main() {
  long long N;
  cin >> N;
  bitset<64> ans;

  for (int i = 0; i != 16; ++i) {
    auto x = ((N + a(i)) >> 2*i) % 4;
    ans.set(2 * i + 1, x & 0x2);
    ans.set(2 * i, x & 0x1);
  }
  
  bool flag{false};
  for (int i = 31; i >= 0; --i) {
    if (flag |= ans.test(i), !flag) continue;
    cout << ans.test(i);
  }
  if (!flag) cout << 0;
  cout << endl;
}
