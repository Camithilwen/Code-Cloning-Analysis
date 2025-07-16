#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=998244353;
ll powmod(ll a, ll k){
    ll ap=a, ans=1;
    while(k){
        if(k&1){
            ans*=ap;
            ans%=MOD;
        }
        ap=ap*ap;
        ap%=MOD;
        k>>=1;
    }
    return ans;
}
ll inv(ll a){
	return powmod(a, MOD-2);
}
int main()
{
	int n, m;
  cin>>n>>m;
  if(n<m) swap(m, n);
  ll f[1000001]; f[0]=1;
  for(ll i=1; i<=n+m; i++) f[i]=f[i-1]*i%MOD;
  ll invf[1000001];
  invf[n+m]=inv(f[n+m]);
  for(ll i=n+m-1; i>=0; i--) invf[i]=invf[i+1]*(i+1)%MOD;
  ll ans=n;
  ll tot=f[n+m]*invf[n]%MOD*invf[m]%MOD;
  ll tinv=inv(tot);
  for(int i=0; i<m; i++){
    ans+=f[n-m+2*i]*invf[i]%MOD*invf[n-m+i]%MOD*f[2*m-2*i-1]%MOD*invf[m-i]%MOD*invf[m-i-1]%MOD*tinv%MOD;
    ans%=MOD;
  }
  cout<<ans<<endl;
  return 0;
}