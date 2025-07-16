#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  string ss;
  cin >> ss;
  int s[10];
  for (int i = 0; i < ss.size(); ++i) {
    s[i] = ss[i] - (char)'0';
  }

  int diff = 1000;
  for (int i = 0; i < ss.size() - 2; ++i) {
    int n = s[i] * 100 + s[i + 1] * 10 + s[i + 2];
    diff = min(diff, abs(753 - n));
  }
  cout << diff << endl;

  return 0;
}
