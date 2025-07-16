#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <bitset>
#include <complex>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <cassert>
#include <functional>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template<typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 1000010

int dp[SIZE][2];

int main() {
  char S[SIZE];

  scanf("%s", S);
  int N = strlen(S);

  for (int i = 0; i <= N; i++)
    dp[i][0] = dp[i][1] = INF;

  dp[0][0] = 0;
  dp[0][1] = 1;

  for (int i = 0; i < N; i++) {
    int p = S[i] - '0';

    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + p);
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 10 - p);

    dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + p + 1);
    dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 10 - p - 1);
  }

  cout << dp[N][0] << endl;

  return 0;
}
