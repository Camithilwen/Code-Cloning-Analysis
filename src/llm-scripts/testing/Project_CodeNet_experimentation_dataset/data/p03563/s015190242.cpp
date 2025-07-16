#include <bits/stdc++.h>
using namespace std;

int main() {
  double a;  /* 現在のレーティング */
  double b;  /* 目標のレーティング */
  
  // 
  // ( a + x ) / 2 = b
  // x = 2b -a
  //
  
  cin >> a;
  cin >> b;
  
  cout << (2.0 * b) - a << endl;
  
}