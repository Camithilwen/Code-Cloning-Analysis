#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
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

ll mod1 = 998244353;

ll mypow(ll a, ll b) {
  ll h = b;
  ll two;
  ll ans = 1;
  ll tmp;
  while(h>0) {
    two = 1;
    tmp = a;
    while(2*two<h) {
      two *= 2;
      tmp *= tmp;
      tmp %= mod1;
    }
    h -= two;
    ans *= tmp;
    ans %= mod1;
  }
  return ans;
}

int main() {
  int N;
  cin>>N;
  int D[N];
  map<int, int> amap;
  for(int i=0;i<N;++i) {
    cin>>D[i];
    amap[D[i]]++;
  }
  if(D[0]>0 || amap[0]>1) {
    cout<<0<<endl;
    return 0;
  }
  ll ans = 1;
  ll num = 1;
  int maxnum=0;
  bool can = true;
  bool owari = false;
  for(int i=0;i<N;++i) {
    if(amap[i]>0) {
      if(owari) can = false;
      maxnum = i;
    }
    else {
      owari = true;
    }
  }
  if(!can) {
    cout<<0<<endl;
    return 0;
  }
  for(int i=1;i<=maxnum;++i) {
    ans *= mypow(num, amap[i]);
    ans %= mod1;
    num = amap[i];
  }
  cout<<ans<<endl;
}

