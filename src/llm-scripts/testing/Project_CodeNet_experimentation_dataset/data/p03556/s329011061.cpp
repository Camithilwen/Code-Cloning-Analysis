#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll n;
  cin >> n;
  
  ll ans;
  for(int i = 1; i * i <= n; i++){
    ans = i*i;
  }
  
  cout << ans << endl;
}