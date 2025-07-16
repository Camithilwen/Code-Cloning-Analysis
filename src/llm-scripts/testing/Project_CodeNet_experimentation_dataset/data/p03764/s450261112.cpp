#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
main()
{
    ll n,m,a=0,b=0,temp=0,prev,ans,i;
    scanf("%lld %lld",&n,&m);
    ll len[n],wid[m];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&len[i]);
    }
    sort(len,len+n);
    for(i=0;i<m;i++)
    {
        scanf("%lld",&wid[i]);
    }
    sort(wid,wid+m);

    for(i=1;i<n;i++)
    {
       a=a+(len[i]-len[0]);
       //printf("%lld\n",a);
    }
    temp=a;
    for(i=1;i<n;i++)
    {
      prev=temp;
      temp=prev-(n-i)*(len[i]-len[i-1]);
      a=a%mod+temp%mod;
      //printf("%lld\n",a);
    }

    for(i=1;i<m;i++)
    {
       b=b+(wid[i]-wid[0]);
       //printf("%lld\n",b);
    }
    temp=b;
    for(i=1;i<m;i++)
    {
      prev=temp;
      temp=prev-(m-i)*(wid[i]-wid[i-1]);
      b=b%mod+temp%mod;
      //printf("%lld\n",b);
    }
    ans=((a%mod)*(b%mod))%mod;
    printf("%lld\n",ans);
}
