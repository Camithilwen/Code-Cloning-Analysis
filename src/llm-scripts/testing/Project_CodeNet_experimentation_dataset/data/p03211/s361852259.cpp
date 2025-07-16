#include <bits/stdc++.h>
using namespace std;

int main() {
  int m = 999;
  string S;
  cin >> S;

  for (int i = 0; i < S.length() - 2; i++) {
    int num;
    istringstream ss;
    ss = istringstream(S.substr(i, 3));
    ss >> num;
    int res = num - 753;
    int diff = res < 0 ? -res : res;
    m = min(diff, m);
  }

  cout << m << endl;
}