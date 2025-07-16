#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

int main() {
  string s;
  while(cin >> s) {
    int state = 0;
    int J, O, I;
    int ans = 0;
    REP(i, s.size()) {
      if (s[i] == 'J') {
        if (state == 1) {
          J++;
        } else {
          state = 1;
          J = 1;
        }
      } else if (s[i] == 'O') {
        if (state == 1) {
          state = 2;
          O = 1;
        } else if (state == 2) {
          O++;
        } else state = 0;
      } else {
        if (state == 2) {
          state = 3;
          I = 1;
          if (J>=O&&I>=O)
            ans = max(ans, O);
        } else if (state == 3) {
          I++;
          if (J>=O&&I>=O)
            ans = max(ans, O);
        } else {
          state = 0;
        }
      }
      //cout << J << " " << O << " " << I << "  : " << state << endl;
    }
    cout << ans << endl;
  }
}