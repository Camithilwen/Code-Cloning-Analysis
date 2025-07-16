#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define run ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0);
#define MOD 1000000007
#define ms(a,x) memset(a,x,sizeof(a))


int main() 
{ 
    run;
   ll n,i,ans=0;
   cin>>n;
   ll a[n], b[n+1]={0};
   for(i=0;i<n;i++)
   {
      cin>>a[i];
     b[i+1]+=b[i]+a[i];
    }
      for(i=0;i<n;i++)
      {
     ll sum=(b[n]-b[i+1])%MOD;
    	ans+=a[i]*sum;
    	ans%=MOD;
      }
      cout<<ans<<endl;
      
      
} 
