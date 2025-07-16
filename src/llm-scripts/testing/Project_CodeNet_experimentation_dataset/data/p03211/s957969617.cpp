#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int res = 100000;
  for (int i = 0; i + 2 < S.size(); ++i) {
    int val = (S[i]-'0')*100 + (S[i+1]-'0')*10 + (S[i+2]-'0');
    res = min(res, abs(val - 753));
  }
  cout << res << endl;
}