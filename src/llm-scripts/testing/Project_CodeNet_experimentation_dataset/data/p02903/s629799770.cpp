#include<iostream>
using namespace std;
int main () {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  int zo[] = {0, 1};
  for (int i = 0; i < B; i ++) {
    for (int j = 0; j < A; j ++) {
      cout << zo[0];
    }
    for (int j = A; j < W; j ++) {
      cout << zo[1];
    }
    cout << endl;
  }
  for (int i = B; i < H; i ++) {
    for (int j = 0; j < A; j ++) {
      cout << zo[1];
    }
    for (int j = A; j < W; j ++) {
      cout << zo[0];
    }
    cout << endl;
  }
}
