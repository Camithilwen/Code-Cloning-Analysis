#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;
LL p = 1000000007ll;

int main(void)
{
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &x: a) cin >> x;
  vector<vector<int> > cnt0(1<<20);
  int zeros = 0;
  int part = 0;
  for(auto x:a) {
    part ^= x;
    if(part) cnt0[part].push_back(zeros);
    else ++zeros;
  }
  if(part) {
    LL pre = 0;
    LL j = 1;
    LL k = 0;
    for(auto c:cnt0[part]) {
      LL tmp = c-pre;
      j += k*tmp;
      j %= p;
      k += j;
      k %= p;
      pre = c;
    }
    cout << j << endl;
    return 0;
  } else {
    LL answer = 1;
    REP(i,zeros-1) {
      answer *= 2;
      answer %= p;
    }
    FOR(i,1,1<<20) {
      LL pre = 0;
      LL j = 1;
      LL k = 0;
      for(auto c:cnt0[i]) {
        LL tmp = c-pre;
        j += k*tmp;
        j %= p;
        k += j;
        k %= p;
        pre = c;
      }
      answer += k;
      answer %= p;
    }
    cout << answer << endl;
    return 0;
  }
}
