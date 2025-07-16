#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  string a, b, c;
  cin >> a >> b >> c;
  
  int ai = a.size() - 1;
  int bi = b.size() - 1;
  
  
  if (a[ai] == b[0] && b[bi] == c[0]) cout << "YES" << endl;
  else cout << "NO" << endl;

}