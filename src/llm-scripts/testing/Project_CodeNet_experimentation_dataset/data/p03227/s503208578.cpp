#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string A;
  cin >> A;
  char B, C;
  if(A.size() == 2) {
    cout << A << endl;
  }
  else {
    B = A.at(0);
    C = A.at(2);
    A.at(0) = C;
    A.at(2) = B;
    cout << A << endl;
  }
}
