#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll x; cin>>x;
  ll ans=x/11*2;
  x%=11;
  if(x!=0)
  {
    if(x>=7)
    {
      ans++;
    }
    ans++;
  }  
  cout<<ans<<endl;
  return 0;
}
