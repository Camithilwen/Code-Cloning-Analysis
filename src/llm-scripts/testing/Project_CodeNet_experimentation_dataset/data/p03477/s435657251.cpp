#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  string reply;

  cin >> a >> b >> c >> d;

  a += b;
  c += d;

  if (a > c) {
    reply = "Left";
  } else if (a == c) {
    reply = "Balanced";
  } else {
    reply = "Right";
  }
  cout << reply << endl;
}
