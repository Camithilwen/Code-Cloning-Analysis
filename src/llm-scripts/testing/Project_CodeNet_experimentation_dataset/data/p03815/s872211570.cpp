#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll x;
  cin >> x;
  ll ans = (x / 11) * 2;
  if(ans > 0){
    x %= 11;
  }
  if(x > 6){
    ans += 2;
  }else if(x > 0){
    ans++;
  }
  cout << ans << endl;
}