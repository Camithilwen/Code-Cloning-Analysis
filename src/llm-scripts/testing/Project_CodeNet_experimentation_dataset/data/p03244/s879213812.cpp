// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

int main() {
  int n; cin >> n;
  vector<int> A(n);
  loop(i,0,n) cin >> A[i];
  map<int, int> C_ODD, C_EVEN;
  loop(i,0,n) {
    if (i&1) C_ODD[A[i]]++;
    else C_EVEN[A[i]]++;
  }
  vector<int> R_ODD(2), R_EVEN(2);
  {
    int max_ = 0;
    for (auto &m: C_ODD) if (max_ < m.second) { max_ = m.second; R_ODD[0] = m.first; }
  }
  {
    int max_ = 0;
    for (auto &m: C_EVEN) if (max_ < m.second) { max_ = m.second; R_EVEN[0] = m.first; }
  }
  {
    int max_ = 0;
    for (auto &m: C_ODD) {
      if (R_ODD[0] == m.first) continue;
      if (max_ < m.second) { max_ = m.second; R_ODD[1] = m.first; }
    }
  }
  {
    int max_ = 0;
    for (auto &m: C_EVEN) {
      if (R_EVEN[0] == m.first) continue;
      if (max_ < m.second) { max_ = m.second; R_EVEN[1] = m.first; }
    }
  }
  
  if (R_ODD[0] != R_EVEN[0]) {
    cout << (n/2 - C_ODD[R_ODD[0]]) + (n/2 - C_EVEN[R_EVEN[0]]) << endl;
    return 0;
  }
  if (R_ODD[0] == R_EVEN[0]) {
    ll cost1 =  (n/2 - C_ODD[R_ODD[1]]) + (n/2 - C_EVEN[R_EVEN[0]]);
    ll cost2 =  (n/2 - C_ODD[R_ODD[0]]) + (n/2 - C_EVEN[R_EVEN[1]]);
    cout << min(cost1, cost2) << endl;
    return 0;
  }
  return 0;
}
