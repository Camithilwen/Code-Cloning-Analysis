#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  
  if (N == 1){
    cout << 1 << endl;
    return 0;
  }
  
  vector<int>A(N);
  vector<vector<vector<int>>> data(N, vector<vector<int>>(N, vector<int>(2)));
 
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    for (int j = 0; j < A.at(i); j++) {
      for (int k = 0; k < 2; k++) {
        cin >> data.at(i).at(j).at(k);
      }
    }
  }
 
  int Max = 0;

  // すべての選び方を試して、総和がKになるものがあるかを調べる
  for (int tmp = 0; tmp < (1 << 15); tmp++) {
    bitset<15> s(tmp);  // 最大20個なので20ビットのビット列として扱う
    
    if (N < 15 && s.test(N)) {
      break;
    }
    // ビット列の1のビットに対応する整数を選んだとみなして総和を求める
    int count = 0;
    int honest = 0;
    
    for (int i = 0; i < N; i++) {
      if (s.test(i)) {
        honest++;
        for (int j = 0; j < A.at(i); j++) {
          int B = data.at(i).at(j).at(0) - 1;
          if (s.test(B)){
            if (data.at(i).at(j).at(1) == 0){
              count++;
            }
          }
          else {
            if (data.at(i).at(j).at(1) == 1){
              count++;
            }
          } 
        }
      }
    }
    if (count == 0){
      if (honest > Max){
        Max = honest;
      }
    }
  }
  
  cout << Max << endl;
}

