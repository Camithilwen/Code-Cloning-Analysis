#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H, W;
  cin >> N >> H >> W;

  int cnt = 0;
  for (int i = H; i <= N; i++) {
    for (int j = W; j <= N; j++) {
      if (N >= i && N >= j) cnt++;
    }
  }

  cout << cnt << endl;
}