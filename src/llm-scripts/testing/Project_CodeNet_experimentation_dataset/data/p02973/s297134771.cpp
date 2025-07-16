#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
ll dp[5009];
  ll a[5000];
int main()
{
  ll n;ll ans=0;
  multiset<ll>s;cin>>n;
  for(int i=0;i<n;i++){
      ll x;cin>>x;
      if(s.size()==0){
          s.insert(x);
          ans++;
          }
          else
          {
              auto z=s.begin();
              if(*z>=x){
                  s.insert(x);ans++
;              }else{
              auto it=s.lower_bound(x);it--;
              s.erase(s.find(*it));
               s.insert(x);
}
    
}
  }cout<<ans;

}