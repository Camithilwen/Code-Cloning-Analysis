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
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

const long long MOD = 1000000007;
long long N;
long long a[100000] = {0};

int main() {
  cin >> N;
  long long ans = 1;
  rep(i, N) {
    long long A;
    cin >> A;
    long long temp;
    if(A == 0) {
      temp = 3 - a[A];
    } else {
      temp = a[A-1] - a[A];
    }
    ans =  ans * temp % MOD;
    a[A]++;
  }
  if(ans <= 0) cout << 0 << endl;
  else cout << ans << endl;
  return 0;
}