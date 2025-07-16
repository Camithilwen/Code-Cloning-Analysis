#include <bits/stdc++.h>
using namespace std;

int main() {
  int L;
  string S;
  cin >> L >> S;
  if (S.size() <= L) {
    cout << S << endl;
  } else {
    cout << S.erase(L) << "..." << endl;
  }
}