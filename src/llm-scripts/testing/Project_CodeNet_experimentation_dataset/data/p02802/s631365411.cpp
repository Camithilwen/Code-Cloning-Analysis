#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
  ll n,m;
  cin >> n >> m;
  
  ll p[m];
  string s[m];
  rep(i,m) cin >> p[i] >> s[i];
  
  ll acnum[n+1];
  for(ll i = 0; i < m; i++){
    if(s[i] == "AC"){
      acnum[p[i]] = 1;
    }
  }
  
  ll ac = 0, wa = 0;
  ll ok[n+1];
  for(ll i = 1; i <= n; i++) ok[i] = 0;
  for(ll i = 0; i < m; i++){
    if(s[i] == "WA" && ok[p[i]] == 0 && acnum[p[i]] == 1){
      wa++;
    }
    if(s[i] == "AC" && ok[p[i]] == 0){
      ok[p[i]] = 1;
      ac++;
    }
  }
  
  cout << ac << " " << wa << endl;
}