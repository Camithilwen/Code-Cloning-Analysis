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
#include <functional>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

int main() {
  vector<int> v1(10),v2(10);
  REP(i,10)
    cin >> v1[i];
  REP(i,10)
    cin >> v2[i];
  sort(ALL(v1), greater<int>());
  sort(ALL(v2), greater<int>());
  cout << v1[0]+v1[1]+v1[2] << " " << v2[0]+v2[1]+v2[2] << endl;
}