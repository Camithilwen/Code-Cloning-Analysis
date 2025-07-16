#include<bits/stdc++.h>
#define int long long
using namespace std;int n,d,a[220001],b[220001];main(){cin>>n>>d;for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];for(int i=2;i<=n;i++)b[i]=min(b[i],b[i-1]+d);for(int i=n-1;i;i--)b[i]=min(b[i],b[i+1]+d);int pos=min_element(a+1,a+1+n)-a,ans=0;for(int i=pos-1;i;i--)ans+=a[i]+b[i+1]+d;for(int i=pos+1;i<=n;i++)ans+=a[i]+b[i-1]+d;cout<<ans<<'\n';}
