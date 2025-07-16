#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  
  bool ok = false;
  REP(i,3){
    if(s[i] == '7') ok = true;
  }

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  
}