#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int N = s.size();
  bool b = true;
  int l = 0, r = 0, eli = 0;
  for (int i = 0; i < N; i++) {
    if (!b && s[i] == 'S') {
      b = true;
      int p = min(l,r);
      eli += 2*p;
      l -= p; r = 0;
    }
    if (s[i] == 'S') l++;
    if (s[i] == 'T') {
      b = false;
      r++;
    }
  }
  eli += 2*min(l,r);
  cout << N - eli << endl;
}