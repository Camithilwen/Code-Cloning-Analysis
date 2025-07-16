#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 1;
const ll mo = 1000000007;

int main()
{
ll n , m ;
cin >> n >> m ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
vector<ll> b(m);
rep(i, m){
  cin >> b[i];
}
sort(a.rbegin(),a.rend());
sort(b.rbegin(),b.rend());
rep(i,n-1)if(a[i]==a[i+1])ans=0;
rep(i,m-1)if(b[i]==b[i+1])ans=0;
a.push_back(-1);
b.push_back(-1);
if(a[0]!=n*m||b[0]!=n*m)ans=0;
ll in=0,im=0;
for (ll i = n*m; i > 0; i--)
{
  while(i<a[in]&&in!=n)in++;
  while(i<b[im]&&im!=m)im++;
  if(a[in]==i&&b[im]==i)continue;
  else if(a[in]==i)ans=(ans*im)%mo;
  else if(b[im]==i)ans=(ans*in)%mo;
  else{
    if(in*im-n*m+i<=0)ans=0;
    else ans=(ans*(in*im-n*m+i))%mo;
  }
}

cout << ans << endl;
return 0;
}