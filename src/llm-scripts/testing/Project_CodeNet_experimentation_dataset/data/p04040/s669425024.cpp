#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll H, W, A, B;
  cin>>H>>W>>A>>B;
  H--;
  W--;
  ll ue[H+W+1];
  ue[0] = 1;
  for(ll i=1;i<=H+W;++i){
    ue[i] = ue[i-1]*i%mod;
  }
  ll ans = ue[H+W];
  ll h = mod - 2;
  ll shita1=1, shita2=1, shita3=1, shita4=1;
  ll tmpshita1, tmpshita2, tmpshita3, tmpshita4;
  ll two;
  while(h>0){
    tmpshita1 = ue[H];
    tmpshita2 = ue[W];
    two = 1;
    while(2*two<=h){
      two *= 2;
      tmpshita1 *= tmpshita1;
      tmpshita1 %= mod;
      tmpshita2 *= tmpshita2;
      tmpshita2 %= mod;
    }
    h -= two;
    shita1 *= tmpshita1;
    shita1 %= mod;
    shita2 *= tmpshita2;
    shita2 %= mod;
  }
  ans = ans*shita1%mod*shita2%mod;
  ll tmpans;
  for(ll i=0;i<B;++i){
    tmpans = ue[H-A+i]*ue[W+A-i-1]%mod;
    shita1 = 1;
    shita2 = 1;
    shita3 = 1;
    shita4 = 1;
    h = mod - 2;
    two = 1;
    while(h>0){
      two = 1;
      tmpshita1 = ue[i];
      tmpshita2 = ue[H-A];
      tmpshita3 = ue[W-i];
      tmpshita4 = ue[A-1];
      while(2*two<=h){
        two *= 2;
        tmpshita1 *= tmpshita1;
        tmpshita2 *= tmpshita2;
        tmpshita3 *= tmpshita3;
        tmpshita4 *= tmpshita4;
        tmpshita1 %= mod;
        tmpshita2 %= mod;
        tmpshita3 %= mod;
        tmpshita4 %= mod;
      }
      h -= two;
      shita1 *= tmpshita1;
      shita2 *= tmpshita2;
      shita3 *= tmpshita3;
      shita4 *= tmpshita4;
      shita1 %= mod;
      shita2 %= mod;
      shita3 %= mod;
      shita4 %= mod;
    }
    tmpans = tmpans*shita1%mod*shita2%mod*shita3%mod*shita4%mod;
    ans = (ans-tmpans+mod)%mod;
  }
  cout<<ans<<endl;
}

