#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  ll A,B; cin >> A >> B;
  if(A<B) swap(A,B);
  ll y = gcd(A,B);
  ll yy = y;
  ll x = 2;
  ll ans = 1;
  while(x*x<=y&&yy!=1){
    if(yy%x==0){
      ans++;
      while(yy%x==0) yy /= x;
    }
    x++;
  }
  if(yy!=1) ans++;
  cout << ans << endl;
}