#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N, A, B, C, D, E; cin >> N >> A >> B >> C >> D >> E;
  
  int k = min(min(min(min(A,B),C),D),E);
  int ans = (N+k-1)/k+4;

  
  cout << ans << endl;
  
}
