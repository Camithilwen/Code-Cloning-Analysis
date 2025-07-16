#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

int prime(int N) {
  if(N<2) return 0;
  if(N == 2) return 1;
  if(N%2 == 0) return 0;
  int sq = (int)(sqrt(N))+1;
  for(int i=3; i<sq; i+=2) {
    if(N%i == 0) return 0;
  }
  return 1;
}


signed main() {
  int N, M; cin >> N >> M;
  
  if(prime(M) == 1 && N >= 2) {
    cout << 1 << endl;
    return 0;
  }
  
  for(int i=N; i<=M; i++) {
    if(M%i == 0) {
      cout << M/i << endl;
      return 0;
    }
  }
    
  
}