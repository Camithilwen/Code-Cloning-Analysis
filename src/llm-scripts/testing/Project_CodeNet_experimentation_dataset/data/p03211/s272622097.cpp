#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  ll s;
  cin >> s;
  int cnt = 0;
  ll S = s;
  while(S > 0){
    S /= 10;
    cnt++;
  }
  const int f = 753;
  int ans = 1000;
  for(int i = 3; i <= cnt; i++){
    int x = s/pow(10,cnt -i);
    ans = min(abs(x-f), ans);
    ll p = pow(10,cnt+2-i);
    s %= p;
  }
  cout << ans << endl;
}
  
    