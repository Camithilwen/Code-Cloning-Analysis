#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i,0,n)
#define BFOR(bit,a,b) for(int bit = (a); bit < (1<<(b)); ++bit)
#define BREP(bit,n) BFOR(bit,0,n)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  if(n < 1200) cout << "ABC" << endl;
  else if(n < 2800) cout << "ARC" << endl;
  else cout << "AGC" << endl;

}