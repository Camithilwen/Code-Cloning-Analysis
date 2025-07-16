#include <bits/stdc++.h>
using namespace std;

int main() {
  
  
  string SA, SB, SC;
  cin >> SA >> SB >> SC;
  
  int ind_A = 1, ind_B = 0, ind_C = 0;
  
  char cur = SA[0];
  
  while(true) {
    
    
    // 文字を見る
    if (cur == 'a') {
      
      
      // 終了条件のチェック
      if (ind_A == SA.size()) {
        cout << "A" << endl;
        return 0;
      } else { // 終了しない場合の cur の更新
        cur = SA[ind_A];
        ind_A++;
      }
    } else if (cur ==  'b') {
    
      // Bのカードを見る
      
      // 終了条件のチェック
      if (ind_B == SB.size()) {
        cout << "B" << endl;
        return 0;
      } else { // 終了しない場合の cur の更新
        cur = SB[ind_B];
        ind_B++;
      }
    } else {
      
      // 終了条件のチェック
      if (ind_C == SC.size()) {
        cout << "C" << endl;
        return 0;
      } else { // 終了しない場合の cur の更新
        cur = SC[ind_C];
        ind_C++;
      }
    }
  }
  
}