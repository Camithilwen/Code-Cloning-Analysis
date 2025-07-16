#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
  
int main() {
  int N,K; cin >> N >> K;
  int D[K]; rep(i,K) cin >> D[i];
 
  int ans = N;
  while (true) {
    int tmp = ans; 
    bool check = true;
    while (check && tmp >0) {
      int a = tmp % 10;
      rep(i,K) if (a == D[i]) {
        check = false; 
        break;
      }
      if (check) {
        tmp /= 10;
      } else {
        ans++; 
        break;
      }
    }
    if (check) break;
  }
  cout << ans << endl;
}