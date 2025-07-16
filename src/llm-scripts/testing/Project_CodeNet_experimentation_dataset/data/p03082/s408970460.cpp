#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll mod=1e9+7;
ll fac[210];

void modfac(ll n){
    fac[0]=1;
    for(ll i=1;i<n;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
}

ll modinv(ll a){
    ll b=mod,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b; swap(a,b);
        u-=t*v; swap(u,v);
        }
        u%=mod;
        if(u<0) u+=mod;
    return u;
}

ll dp[210][100010];

int main(){
  ll n,x;
  cin >> n >> x;
  ll a[n];
  for(ll i=0;i<n;i++) cin >> a[i];
  sort(a,a+n);
  reverse(a,a+n);
  ll inv[n+1];
  for(ll i=1;i<=n;i++) inv[i]=modinv(i);
  for(ll i=0;i<=x;i++) dp[n][i]=i;
  for(ll i=n-1;i>=0;i--){
    for(ll j=0;j<=x;j++){
      ll p=n-i;
      dp[i][j]=inv[p]*(dp[i+1][j%a[i]]+(p-1)*dp[i+1][j]%mod)%mod;
    }
  }
  modfac(210);
  cout << dp[0][x]*fac[n]%mod << endl;
}