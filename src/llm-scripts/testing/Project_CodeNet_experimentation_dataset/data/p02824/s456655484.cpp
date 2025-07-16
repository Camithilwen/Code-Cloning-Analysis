#include <bits/stdc++.h>
#define pb push_back
#define int long long 
using namespace std;

inline int read()
{
	int sum=0,ff=1; char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(isdigit(ch))
		sum=sum*10+(ch^48),ch=getchar();
	return sum*ff;
}

const int N=1e5+5;

int n,m,a[N],k,p,b[N];

signed main()
{
	n=read();
	m=read();
	k=read();
	p=read();
	for ( int i=1;i<=n;i++ ) 
		a[i]=read();
	sort(a+1,a+n+1); 
	reverse(a+1,a+n+1);
	for ( int i=1;i<=n;i++ ) b[i]=b[i-1]+a[i];
	int ans=p;
	int i;
	for ( i=p+1;i<=n;i++ )
	{
		if(a[i]+m<a[p]) continue;
		int j=i;
//		while(a[j]==a[i]&&j<=n) j++;
//		j--;
		int sum=(n-i+1)+(p-1); 
		if(sum>=k) ans+=(j-i+1);
		else 
		{
			int alb=b[i-1]-b[p-1];
			int need=(k-((n-i+1)+(p-1)))*m;
			if(((a[i]+m)*(i-p)-alb)>=need) ans+=(j-i+1);
		}
		i=j;
	}
	printf("%lld\n",ans);
	return 0;
}

			
			
		
	