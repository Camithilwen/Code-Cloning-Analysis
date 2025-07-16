#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if (A == B && B == C) cout << "No" << endl;
  else if (A == B || B == C || C == A) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
