#include<bits/stdc++.h>
#define int long long
using namespace std;
int d,ans,p[25];
int Abs(int x)
{
	return x<0?-x:x;
}
signed main()
{
	cin>>d;
	p[0]=1LL;
	for(int i=1;i<=20;i++) p[i]=p[i-1]*10LL;
	for(int i=2;i<=20;i++)
	{
		int k=i/2;
		for(int s=0;s<(1<<k);s++)
		{
			int w,x=d;
			if(i&1) w=10;
			else w=1;
			for(int j=0;j<k;j++)
			{
				int d2=Abs(x)%10LL;
				if(x<0) d2=(10-d2)%10;
				if(s&(1<<j))
				{
					int n=10LL-d2;
					if(j==0) n--;
					w*=n;
					x+=d2*p[i-2*j-1];
					x-=d2;
				}
				else
				{
					int n=d2;
					if(j==0) n--;
					if(n<0)
					{
						w=0;
						break;
					}
					w*=n;
					x-=(10LL-d2)*p[i-2*j-1];
					x+=10LL-d2;
				}
				x/=10LL;
			}
			if(!x) ans+=w;
		}
	}
	cout<<ans;
	return 0;
}