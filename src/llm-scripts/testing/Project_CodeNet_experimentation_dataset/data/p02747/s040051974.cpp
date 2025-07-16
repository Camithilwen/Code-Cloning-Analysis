#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  int l = S.length();
  if (l == 1) {
    cout << "No" << endl;
    return 0;
  }

  if (l % 2 == 1) {
    cout << "No" << endl;
    return 0;
  }

  string expected = "";
  while (l > 0) {
    expected += "hi";
    l -= 2;
  }

  if (S == expected) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
