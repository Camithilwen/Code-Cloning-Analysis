#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int H, W, A, B;
  cin >> H >> W >> A >> B;

  if ((H / 2) < B || (W / 2) < A) {
    cout << -1 << endl;
    return 0;
  }

  rep(i, H) {
    char out = '0';
    if (i >= B) out = '1';
    rep(j, W) {
      if (j < A)
        cout << out;
      else
        cout << ((out == '0') ? '1' : '0');
    }
    cout << endl;
  }
  return 0;
}