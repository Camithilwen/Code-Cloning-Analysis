#include <bits/stdc++.h>
using namespace std;

int main() {
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  if(a1 <= a3 && a3 <= a2 || a2 <= a3 && a3 <= a1) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
