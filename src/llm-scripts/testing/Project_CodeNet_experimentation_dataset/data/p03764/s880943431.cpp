#include<iostream>
#include<algorithm>
#define MOD 1000000007
using namespace std;
typedef long long ll;
signed main(){
  ll n,m,xsum=0,ysum=0,ans=0;
  cin >> n >> m;
  ll tx[n],ty[m],x[n],y[m];
  for(ll i=0;i<n;i++){
    cin >> tx[i];
  }
  for(ll i=0;i<m;i++){
    cin >> ty[i];
  }
  sort(tx,tx+n);
  sort(ty,ty+m);
  n--; m--;
  for(ll i=0;i<n;i++){
    x[i]=tx[i+1]-tx[i];
    x[i]%=MOD;
  }
  for(ll i=0;i<m;i++){
    y[i]=ty[i+1]-ty[i];
    y[i]%=MOD;
  }
  for(ll i=0;i<n;i++){
    if(i==0||i==n-1){
      xsum+=x[i]*n;
    }else{
      xsum+=((((i+1)*(n-i))%MOD)*x[i])%MOD;
    }
    xsum%=MOD;
  }
  for(ll i=0;i<m;i++){
    if(i==0||i==m-1){
      ysum+=y[i]*m;
    }else{
      ysum+=((((i+1)*(m-i))%MOD)*y[i])%MOD;
    }
    ysum%=MOD;
  }
  ans = xsum*ysum;
  ans%=MOD;
  cout << ans<<endl;
}
