#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i,0,n)
#define BFOR(bit,a,b) for(int bit = (a); bit < (1<<(b)); ++bit)
#define BREP(bit,n) BFOR(bit,0,n)
using namespace std;
using ll = long long;

int main() {
  ll x;
  cin >> x;
  ll ans = (x/11) * 2;
  
  if(x%11 > 0 && x%11 <= 6) ans += 1;
  if(x%11 >= 7) ans += 2;
  
  cout << ans << endl;
    
}