#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll n;
  cin >> n;
  
  ll a[n];
  rep(i,n) cin >> a[i];
  
  int ans = 0;
  while(1){
    rep(i,n){
      if(a[i] % 2 == 0){
        a[i] /= 2;
      }else{
        cout << ans << endl;
        return 0;
      }
    }
    ans++;
  }
}