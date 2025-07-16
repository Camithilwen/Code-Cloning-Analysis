#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

int main() {
  int n;
  cin >> n;
  while(n--) {
    string s;
    int out = 0;
    vector<int> rui(3);
    int ten = 0;
    while(out < 3) {
      // FOR(it,rui)
      //   cout << *it << " ";
      // cout << endl;
      cin >> s;
      if (s == "HIT") {
        if (rui[2]) ten++;
        rui[2] = rui[1];
        rui[1] = rui[0];
        rui[0] = 1;
      } else if (s == "HOMERUN") {
        REP(i,3) {
          ten += rui[i];
        }
        ten++;
        rui = vector<int>(3);
      } else
        out++;
    }
    cout << ten << endl;
  }
}