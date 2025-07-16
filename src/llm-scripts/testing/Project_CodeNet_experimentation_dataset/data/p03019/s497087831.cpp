#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;
typedef long long ll;
//typedef pair<int,int> Pint;
typedef pair<ll, ll> P;
//typedef pair<int, pair<int, int>> P;
//typedef tuple<int,int,int> T;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define revrep(i, n) for(ll i = n-1; i >= 0; i--)
ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}

ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 1000000000;//10^9
ll MOD  = 1000000007;
//vector<int> dy = {0,0,1,-1};
//vector<int> dx = {1,-1,0,0};

ll N, X;
vector<tuple<ll, ll, ll, ll>> test(100010);
ll A;
vector<ll> sum(100010);

bool can(ll point){
  if(point == N * X) return 1;
  ll rest = point % X;
  ll perfect = point / X;
  rep(i, N){
    ll T = 0;
    if(perfect <= i) T += sum[perfect];
    else T += sum[perfect+1] - get<0>(test[i]);
    if(rest >= get<1>(test[i])) T += rest * get<3>(test[i]) - get<1>(test[i]) * (get<3>(test[i]) - get<2>(test[i]));
    else T += rest * get<2>(test[i]);
    if(T >= A) return 1;
  }
  return 0;
}

//　貢献度, b, l, u 0 1 2 3
int main(void){
  cin >> N >> X;
  test.resize(N);
  sum.resize(N+1);
  rep(i, N){
    cin >> get<1>(test[i]) >> get<2>(test[i]) >> get<3>(test[i]);
    get<0>(test[i]) = X * get<3>(test[i]) - get<1>(test[i]) * (get<3>(test[i]) - get<2>(test[i]));
    A += get<1>(test[i]) * get<2>(test[i]);
  }
  sort(test.begin(), test.end());
  reverse(test.begin(), test.end());
  rep(i, N) sum[i+1] = sum[i] + get<0>(test[i]);
  ll lose = -1, win = N * X;
  ll mid;
  while(win - lose > 1){
    mid = (lose + win) / 2;
    if(can(mid)){
      win = mid;
    }else{
      lose = mid;
    }
  }
  cout << win << endl;
}
