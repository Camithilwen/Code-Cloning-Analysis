#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<30;

int main() {
  int n;
  while(cin>>n,n) {
    REP(i,n) {
      int m,e,j;
      cin >> m >> e >> j;
      char c;
      if (m == 100 || e == 100 || j == 100)
        c = 'A';
      else if (m + e >= 180)
        c = 'A';
      else if (m + e + j >= 240)
        c = 'A';
      else if (m + e + j >= 210)
        c = 'B';
      else if (m + e + j >= 150 && (m >= 80 || e >= 80))
        c = 'B';
      else
        c = 'C';
      cout << c << endl;
    }
  }
}