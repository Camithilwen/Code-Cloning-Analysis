#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  for (int i = 0; i < B; i++) {
    for (int j = 0; j < A; j++) {
      cout << 0;
    }
    for (int j = A; j < W; j++) {
      cout << 1;
    }
    cout << endl;
  }
  for (int i = B; i < H; i++) {
    for (int j = 0; j < A; j++) {
      cout << 1;
    }
    for (int j = A; j < W; j++) {
      cout << 0;
    }
    cout << endl;
  }
  return 0;
}