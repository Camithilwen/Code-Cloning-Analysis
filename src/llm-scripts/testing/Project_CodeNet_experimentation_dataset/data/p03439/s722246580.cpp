#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

vector<string> v;

void init() { rep(i, 0, 7) cin >> v[i]; }
string test(int i) { return v[i]; }

int main() {
  int n;
  cin >> n;

  int maxs = 19, mid = 0, head = 0, tail = n - 1;
  string old_input, input;

  cout << 0 << endl;
  cin >> input;
  old_input = input;
  // v.resize(n);
  // init();
  // old_input = input = test(0);
  if (input == "Vacant")
    return 0;

  while (maxs--) {
    mid = head + ((tail + 1) - head) / 2;
    cout << mid << endl;
    cin >> input;
    // input = test(mid);

    if (input == "Vacant")
      return 0;
    if ((mid - head) & 1) {
      if (old_input == input) {
        tail = mid;
      } else {
        head = mid;
        old_input = input;
      }
    } else {
      if (old_input == input) {
        head = mid;
        old_input = input;
      } else {
        tail = mid;
      }
    }
  }
}
