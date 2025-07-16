#include <bits/stdc++.h>
using namespace std;
int main(){
  int x, y;
  cin >> x >> y;
  if (x == 0){
    if (y >= 0){
      cout << y << endl;
    } else {
      cout << 1 - y << endl;
    }
  } else if (y == 0){
    if (x <= 0){
      cout << -x << endl;
    } else {
      cout << x + 1 << endl;
    }
  } else if (x <= y){
    if (x >= 0 && y >= 0){
      cout << y - x << endl;
    } else if (x <= 0 && y <= 0){
      cout << y - x << endl;
    } else if (abs(x) <= abs(y)){
      cout << y + x + 1 << endl;
    } else {
      cout << -x - y + 1 << endl;
    }
  } else {
    if (x >= 0 && y >= 0){
      cout << x - y + 2 << endl;
    } else if (y <= x && x <= 0){
      cout << x - y + 2 << endl;
    } else if (abs(x) <= abs(y)){
      cout << -x - y + 1 << endl;
    } else {
      cout << x + y + 1 << endl;
    }
  }
}