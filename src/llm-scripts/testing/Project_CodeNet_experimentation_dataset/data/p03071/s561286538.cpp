#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A, B;
  cin >> A >> B;
  
  if (A == B) {
    cout << 2 * A << endl;
  }
  else {
    cout << 2 * max(A,B) -1 << endl;
  }

return 0;
}