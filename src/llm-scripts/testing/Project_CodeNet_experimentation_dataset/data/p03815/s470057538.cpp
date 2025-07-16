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
  ll ans = 0;
  
  ll n = x / 11;
  ans += n*2;
  x -= n*11;
  
  if(x == 0){}
  else if(x <= 6){ans += 1;}
  else{ans += 2;}
  
  
  cout << ans << endl;
    

}
