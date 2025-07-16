#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int b;
  int c;
  int d;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  int l = a + b;
  int r = c + d;
  if(l > r){
    cout << "Left" << endl;
  }else if(l == r){
    cout << "Balanced" << endl;
  }else{
    cout << "Right" << endl;
  }
  return 0;
}