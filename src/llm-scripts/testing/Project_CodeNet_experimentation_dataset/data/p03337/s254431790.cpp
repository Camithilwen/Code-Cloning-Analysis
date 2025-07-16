#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B;
  C=max((A+B),(A-B));
  cout << max(C,(A*B)) << endl;
}
