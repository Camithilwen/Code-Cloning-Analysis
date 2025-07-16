#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )
 
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  set<int> paper;
  REP(i, N) {
    int A;
    cin >> A;
    if ( paper.count(A) ) {
      paper.erase(A);
    } else {
      paper.insert(A);
    }
  }

  cout << paper.size() << endl;  

  return 0;
}
