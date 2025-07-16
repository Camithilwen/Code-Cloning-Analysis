#include <bits/stdc++.h>
using namespace std;

int main() {
	int a;
  int b;
  int c;
  bool poor = false;
  cin >> a;
  cin >> b;
  cin >> c;
  if (a == b == c) {
    poor = false;
  } else {
    if (a == b && a != c) {
    poor = true;
  } else {
    if (a == c && a != b) {
    poor = true;
  } else {
    if (b == c && b != a) {
    poor = true;
  } else {
    if (b == a && b != c) {
    poor = true;
  } else {
    if (c == a && c != b) {
    poor = true;
  } else {
    if (c == b && c != a) {
    poor = true;
  } else {
    poor = false;
  }
  }
  }
  }
  }
  }
  }
  
  
  if (poor == true) {
    cout << "Yes";
  } else {
    cout << "No";
  }
	return 0;
}
