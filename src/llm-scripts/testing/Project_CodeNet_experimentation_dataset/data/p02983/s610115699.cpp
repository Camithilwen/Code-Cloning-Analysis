#include <bits/stdc++.h>
using namespace std;
int main() {
  int L,R;
  cin >> L >> R;
  int modL = L % 2019;
  int modR = R % 2019;
  if (R - L >= 2018){
    cout << 0 << endl;
    return 0;
  }
  else if (modL > modR){
    cout << 0 << endl;
    return 0;
  }
  int N = 2019;
  for (int i = modL; i < modR; i++) {
    for (int j = i+1; j <= modR; j++) {
      if (i != j){
        int M = ((i*j) % 2019) % 2019;
        if (M < N){
          N = M;
        }
      }
    }
  }
  cout << N << endl;
}   