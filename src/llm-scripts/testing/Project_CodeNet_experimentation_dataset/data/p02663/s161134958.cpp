#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int hour;
  int min;

  int t1, t2, t3;
  t3 = h2 * 60 + m2;
  t2 = t3 - k;
  t1 = h1 * 60 + m1;

  int ans;
  
  ans = t2 - t1;

  cout << ans << endl;


}