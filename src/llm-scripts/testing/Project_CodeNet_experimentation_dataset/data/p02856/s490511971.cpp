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
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int M;
  cin>>M;
  ll d, c;
  ll ans = 0;
  ll sum = 0;
  for(int i=0;i<M;++i) {
    cin>>d>>c;
    ans += c;
    sum += d*c;
  }
  ans--;
  if(sum%9==0) ans += sum/9-1;
  else ans += sum/9;
  cout<<ans<<endl;
}

