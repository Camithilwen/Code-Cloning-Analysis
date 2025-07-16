#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> ds(N, -1);
  bool isExist = true;
  rep(i, M) {
    int s, c;
    cin >> s >> c;
    s--;
    if (ds[s] == -1) {
      ds[s] = c;
    } else if (ds[s] != c) {
      isExist = false;
    }
  }
  if (!isExist) {
    cout << -1 << endl;
    return 0;
  }
  if (2 <= N) {
    int sum = 0;
    if (ds[0] == 0) {
      cout << -1 << endl;
      return 0;
    } else if (ds[0] == -1) {
      sum = 1;
    } else {
      sum = ds[0];
    }

    for (int i = 1; i < N; i++) {
      if (ds[i] == -1) {
        sum = sum * 10;
      } else {
        sum = sum * 10 + ds[i];
      }
    }
    cout << sum << endl;
    return 0;
  } else {
    if (ds[0] == -1) {
      cout << 0 << endl;
    } else {
      cout << ds[0] << endl;
    }
  }
  return 0;
}