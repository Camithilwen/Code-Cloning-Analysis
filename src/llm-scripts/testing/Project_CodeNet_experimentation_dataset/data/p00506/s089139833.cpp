#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef complex<double> P;

int main() {
  int N; cin >>N;
  if(N == 2){
    int a, b; cin >>a >>b;
    FOR(i, 1, max(a, b) + 1) if(a % i == 0 && b % i == 0) cout <<i <<endl;
  } else{
    int a, b, c; cin >>a >>b >>c;
    FOR(i, 1, max(a, max(b, c)) + 1) if(a % i == 0 && b % i == 0 && c % i == 0) cout <<i <<endl;
  }
  return 0;
}