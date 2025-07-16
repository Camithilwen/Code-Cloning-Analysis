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
const int INF = 1<<29;

int main() {
  int n,m;
  while(cin>>n>>m, n+m) {
    int p[n];
    REP(i,n) 
      cin >> p[i];
    vector<int> v(n*n);
    REP(i,n)
      REP(j,n)
      v[i*n + j] = p[i] + p[j];
    v.push_back(0);
    REP(i,n)
      v.push_back(p[i]);
    sort(ALL(v));
    // FOR(it, v)
    //   cout << *it << " ";
    // cout << endl;
    int res = 0; 
    REP(i,v.size()) {
      vector<int>::iterator it = upper_bound(ALL(v), m-v[i]);
      int tmp;
      if (it == v.begin()) {
        break;
      } else {
        it--;
        tmp = v[i] + *it;
      }
      res = max(res, tmp);
    }
    cout << res << endl;
  }
}