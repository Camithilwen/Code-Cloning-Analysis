#include<bits/stdc++.h>
using namespace std;
int main () {
  int a[4];
  string key = "0123456789";
  for (int i = 0; i < 4; i ++) {
    char c;
    cin >> c;
    for (int j = 0; j < 10; j ++) {
      if (c == key[j]) a[i] = j;
    }
  }
  //4桁の数字を1桁ずつに分解
  for (int i = 0; i < 1 << 3; i ++) {
    int i_ = i;
    char c[3];
    int as_ = a[0];//数字に対応した数式の結果
    for (int j = 0; j < 3; j ++) {
      if (i_ % 2) { //i_ % 2 != 0と同値
        c[j] = '+';
        as_ += a[j + 1];
      }
      else {
        c[j] = '-';
        as_ -= a[j + 1];
      }
      i_ /= 2;
    }
    if (as_ == 7) {
      for (int j = 0; j < 3; j ++) cout << a[j] << c[j];
      cout << a[3] << "=7" << endl;
      return 0;//強制終了
    }
  }
}

