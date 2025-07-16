#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int A, B;
  cin >> A >> B;

  int ans = 0;

  for (int a = 1; a < 10; a++){
    rep(b,10){
      rep(c,10){
        int x = 10001 * a + 1010 * b + 100 * c;
        if (x >= A && x <= B){
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}
