#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, G;
  cin >> R >> G;
  if(0 <= R){
    if(4500 >= G){
      cout << (G - R) * 2 + R << endl;
    }else{
    cout << "Please input number (goal rating) under 4500." << endl;
    }
  }else{
  cout << "Please input number (rating) over 0." << endl;
  }
 }