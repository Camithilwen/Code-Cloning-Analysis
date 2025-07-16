#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, i, a, b, x, y, z = 0;
  cin >> A >> B;
  for (int i = A; i < B + 1; i++){
    a = i / 10000;
    b = (i / 1000) % 10;
    x = i % 10;
    y = (i % 100) / 10;
    if (a == x && b == y){
      z += 1;
    }
    else
      continue;
  }
  cout << z << endl;
}
