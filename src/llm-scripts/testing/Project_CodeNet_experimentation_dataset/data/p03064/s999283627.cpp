#include <iostream>
#include <ccomplex>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <numeric>
#include <list>
#include <assert.h>
#include <math.h>
#include <valarray>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <complex>
#include <list>
#include <time.h>
#include <stack>
#include <locale>
#include <clocale>
#include <ctype.h>
#include <wchar.h>
#include <random>
#include <vector>
#include <unordered_map>
#include <bitset>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SP << " " <<

LL mod = 998244353;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin >> N;
  vector<LL> a(N);

  LL sum = 0;

  REP(i,N){
    cin >> a[i];
    sum += a[i];
  }
  //bound
  sum = (sum - 1) / 2 + 1;

  vector<vector<LL>> v(a.size()+1, vector<LL>(100001, 0));
  v[0][0] = 1;

  REP(i,a.size()){
    REP(j,90001){
      v[i + 1][j] += v[i][j]*2;
      v[i + 1][j+a[i]] += v[i][j];
      v[i + 1][j] %= mod;
      v[i + 1][j + a[i]] %= mod;
    }
  }

  LL ans = 1;

  REP(i,a.size()){
    ans *= 3;
    ans %= mod;
  }

  FOR(i,sum,90001){
    ans -= v[a.size()][i] * 3;
    ans %= mod;
    ans += mod;
    ans %= mod;
  }

  vector<vector<LL>> vv(a.size()+1, vector<LL>(100001, 0));
  vv[0][0] = 1;

  REP(i,a.size()){
    REP(j,90001){
      vv[i + 1][j] += vv[i][j];
      vv[i + 1][j+a[i]] += vv[i][j];
      vv[i + 1][j] %= mod;
      vv[i + 1][j + a[i]] %= mod;
    }
  }

  FOR(i,sum,90001){
    ans += vv[a.size()][i] * 3 *2;
    ans %= mod;
    ans += mod;
    ans %= mod;
  }

  LL cnt = 3;

  REP(i,a.size()){
    cnt *= 2;
    cnt %= mod;
  }

  ans -= cnt;
  ans %= mod;
  ans += mod;
  ans %= mod;

  cout << ans << endl;
}
