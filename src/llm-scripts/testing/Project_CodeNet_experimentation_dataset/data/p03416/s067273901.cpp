#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int a_01 = A / 10000;
  int a_02 = A / 1000 - a_01 * 10;
  int a_03 = A / 100 - a_01 * 100 - a_02 * 10;
  
  int b_01 = B / 10000;
  int b_02 = B / 1000 - b_01 * 10;
  int b_03 = B / 100 - b_01 * 100 - b_02 * 10;
  
  int head = 0, tail = 0;
  
  if (A <= (a_01 * 10000 + a_02 * 1000 + a_03 * 100
            + a_02 * 10 + a_01)){
    head = 1;
  }
  
  if (B >= (b_01 * 10000 + b_02 * 1000 + b_03 * 100
            + b_02 * 10 + b_01)){
    tail = 1;
  }
  
  int sum;
  
  if ((b_01 - a_01) >= 1){
    sum = (b_01 - a_01 - 1) * 100
      + ((9 - a_02) + b_02) * 10
      + ((9 - a_03) + b_03)
      + head + tail;
  }else{
    if ((b_02 - a_02) >= 1){
       sum = (b_02 - a_02 -1) * 10
         + ((9 - a_03) + b_03)
         + head + tail;
    }else{
      if ((b_03 - a_03) >= 1){
        sum = (b_03 - a_03 -1) + head + tail;
      }else{
        if (head == 1 && tail == 1){
          sum = 1;
        }else{
          sum = 0;
        }
      }
    }
  }
      
  cout << sum << endl;
}
