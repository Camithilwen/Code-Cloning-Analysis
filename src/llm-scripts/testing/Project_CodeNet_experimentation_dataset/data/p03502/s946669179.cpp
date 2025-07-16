// ABC 080 B- Harshed Number
/*
  各桁の和ってどうプログラムすればええんだ
  あ、10で割り続けて、商と余りを考えればいいんだ
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum = 0 ;
  cin >> N;

  int N2 = N;
  while (N != 0) { // Nが0になるまで割り続ける。
    sum += N % 10; // 総和を更新して
    N /= 10; // Nを更新 N = N / 10 → N /= 10
  }
  if (N2 % sum == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
