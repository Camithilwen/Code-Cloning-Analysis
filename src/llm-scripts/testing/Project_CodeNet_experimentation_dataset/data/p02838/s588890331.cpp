#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using P = pair<long long, long long>;

const long long MOD = 1000000007;

int main() {
  long long N;
  long long a[60] = {0};
  cin >> N;
  rep(i, N) {
    long long temp;
    cin >> temp;
    long long x = 1;
    rep(j, 60) {
      if(temp & x) {
        a[j]++;
        // cout << j << endl;
      }
      x *= 2;
    }
  }
  long long ans = 0;
  long long x = 1;
  rep(i, 60) {
    ans += ((((a[i] * (N-a[i])) % MOD) * x));
    ans %= MOD;
    x *= 2;
    x %= MOD;
  }
  cout << ans << endl;
  return 0;
}