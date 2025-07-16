#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=1e18;
int main(){
  int n;
  cin >> n;
  vector<ll> a(n),dp(n+1,0);
  for(int i=0;i<n;i++){
    cin >> a[i];
    dp[i+1]=dp[i]+a[i];
  }
  for(int split=2;split+1<n;split++){
    ll p=0,q=dp[split],r=0,s=dp[n];
    auto itr1 = lower_bound(dp.begin(), dp.end(), dp[split]/2);
    auto itr2 = lower_bound(dp.begin(), dp.end(), (dp[n]+dp[split])/2);
    
    for(int d=-1;d<2;d++){
      if(max(p,q-p)>max(*(itr1+d),q-*(itr1+d))){
        p=*(itr1+d);
      }
      if(max(r-q,s-r)>max(*(itr2+d)-q,s-*(itr2+d))){
        r=*(itr2+d);
      }      
    }
    ll diff=max({s-r,r-q,q-p,p})-min({s-r,r-q,q-p,p});
    ans=min(ans,diff);
  }
  cout << ans << endl;
}
