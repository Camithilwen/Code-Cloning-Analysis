#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if (a!=b) {
    cout << max(a,b)*2-1 << endl;
  }
  else
    cout << a*2 << endl;
}