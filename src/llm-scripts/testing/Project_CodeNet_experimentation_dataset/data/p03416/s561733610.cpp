#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  
  int a12 = a/1000;
  int a21 = a12/10 + a12%10*10;
  int b12 = b/1000;
  int b21 = b12/10 + b12%10*10;
  
  // 上２ケタがa12でaより小さいのを弾く
  int count_less_than_a = 0;
  for (int i = 0; i <= 9; i++) {
    if (a12*1000 + i*100 + a21 < a){
      count_less_than_a++;
    }
    else {
      break;
    }
  }
  
  // 上２ケタがb12でbより大きいのを弾く
  int count_more_than_b = 0;
  for (int i = 9; i >= 0; i--) {
    if (b12*1000 + i*100 + b21 > b){
      count_more_than_b++;
    }
    else {
      break;
    }
  }
  
  int result = (b12 - a12 +1) * 10
    - count_less_than_a - count_more_than_b;
  
  cout << result << endl;
  
}
