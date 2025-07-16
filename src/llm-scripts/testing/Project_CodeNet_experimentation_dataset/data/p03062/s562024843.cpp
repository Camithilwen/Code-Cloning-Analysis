#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  int minus = 0;
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    if(A.at(i) < 0) {
      minus++;
    }
  }
  if(minus % 2 == 0) {
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
      ans += abs(A.at(i));
    }
    cout << ans << endl;
  }
  else {
    // 絶対値が一番小さいものをaとする
    int64_t a = 1000000000;
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
      if(abs(A.at(i)) < a) {
        a = abs(A.at(i));
      }
      ans += abs(A.at(i));
    }
    ans -= 2 * a;
    cout << ans << endl;
  }
}