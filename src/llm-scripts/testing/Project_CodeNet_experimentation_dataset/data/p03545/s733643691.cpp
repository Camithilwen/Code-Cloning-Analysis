#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int i, j;
  for (i = 0; i < (1 << 3); i++) {
    bitset<3> a(i);
    int sum = s.at(0) - '0';
    for (j = 0; j < 3; j++) {
      if (a.test(j) == 1) { sum += s.at(j + 1) - '0'; }
      else { sum -= s.at(j + 1) - '0'; }
    }
    if (sum == 7) { break; }
  }
  bitset<3> a(i);
  cout << s.at(0);
  for (j = 0; j < 3; j++) {
    if (a.test(j) == 1) { cout << "+"; }
    else { cout << "-"; }
    cout << s.at(j + 1);
  }
  cout << "=7" << endl;
}
